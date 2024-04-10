#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
	cin>>str;
	for(register int i=0;i<str.length();i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
			str[i]-=('A'-'a');
		}
	}
	for(register int i=0;i<str.length();i++)
	{
		if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u'&&str[i]!='y')
		{
			cout<<"."<<str[i];
		}
		else
		{
			continue;
		}
	}
}