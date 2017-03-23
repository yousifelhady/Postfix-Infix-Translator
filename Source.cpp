#include <iostream>
#include <string>
#include <stack>
using namespace std;

void main ()
{
	string postfix;
	stack<string> mystack;
	cout <<"Welcome to Postfix / Infix translator"<< endl << endl <<"Kindly enter the postfix and separate each character with a space"<< endl << endl;
	getline(cin, postfix);
	postfix += " ";
	int n = postfix.length();
	string* c = new string [n];
	int j = 0;

	for (int ii = 0; ii < n; ii++)
	{
		for (int i = 0; i < postfix.length(); i++) {
			if (postfix[i] == ' ') {
				c[j] = postfix.substr(0, i);
				postfix = postfix.substr(i + 1, postfix.length() - 1);
				j++;
				break;
			}
		}
	}
	
	string input_to_stack;

	for (int i = 0; i < j; i++)
	{
		input_to_stack = c[i];
		if ((input_to_stack == "+" )||(input_to_stack == "-" )||(input_to_stack == "*" )||(input_to_stack == "/" ))
		{
			string second = mystack.top();
			mystack.pop();
			string first = mystack.top();
			mystack.pop();
			string result = "(" + first + c[i] + second + ")";
			mystack.push(result);
		}
		else
		{
			mystack.push(input_to_stack);
		}
	}
	cout << endl;
	cout <<"The desired infix for the entered postfix is" << endl << endl << mystack.top() << endl << endl;
}