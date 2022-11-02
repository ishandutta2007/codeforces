#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string trans="qwertyuiopasdfghjkl;zxcvbnm,./",str;
char moves;
ll ind;
int main()
{
	cin>>moves>>str;
	if(moves=='R')
	{
		for(register int i=0;i<str.length();i++)
		{
			ind=trans.find(str[i]);
			str[i]=trans[ind-1];
		}
	}
	else
	{
		for(register int i=0;i<str.length();i++)
		{
			ind=trans.find(str[i]);
			str[i]=trans[ind+1];
		}
	}
	cout<<str;
}