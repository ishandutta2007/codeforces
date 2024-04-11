#include<iostream>
#include<string>
using namespace std;
int main()
{
	int x=0,n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		if(s[1]=='+')
			x++;
		else
			x--;
	}
	cout << x;
}