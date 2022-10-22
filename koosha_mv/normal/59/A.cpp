#include<iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int b,k;
	b=0;
	k=0;
	for(int i=0;i<s.size();i++)
	{
		if(int(s[i])>=65 && int(s[i])<=90)
			k++;
		else
			b++;
			
	}
	if(k>b)
	{
		for(int i=0;i<s.size();i++)
		{
			if(int(s[i])>93)
				cout << char(int(s[i])-32);
			else
				cout << s[i];
		}
	}
	else
	{
		for(int i=0;i<s.size();i++)
		{
			if(int (s[i])<93)
				cout << char(int (s[i])+32);
			else
				cout << s[i];
		}
	}
		
}