#include<bits/stdc++.h>
using namespace std;
string str;
int lower,upper;
int main()
{
	cin>>str;
	for(register int i=0;i<str.length();i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
			upper++;
		}
		else
		{
			lower++;
		}
	}
	if(upper>lower)
	{
		for(register int i=0;i<str.length();i++)
		{
			if(str[i]>='a'&&str[i]<='z')
			{
				str[i]+=('A'-'a');
			}
		}
		cout<<str;
	}
	else
	{
		for(register int i=0;i<str.length();i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				str[i]-=('A'-'a');
			}
		}
		cout<<str;
	}
	
}