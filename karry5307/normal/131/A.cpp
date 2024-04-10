#include<bits/stdc++.h>
using namespace std;
string str;
bool a=1;
int main()
{
	cin>>str;
	for(register int i=1;i<str.length();i++)
	{
		if(str[i]>=97)
		{
			a=0;
			break;
		}
	}
	if(a==1)
	{
		for(register int i=0;i<str.length();i++)
		{
			if(str[i]>=65&&str[i]<97)
			{
				str[i]+=32;
			}
			else
			{
				str[i]-=32;
			}
		}
	}
	cout<<str;
}