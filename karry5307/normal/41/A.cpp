#include<bits/stdc++.h>
using namespace std;
string code,edoc;
int main()
{
	cin>>code>>edoc;
	if(code.length()!=edoc.length())
	{
		cout<<"NO";
		return 0;
	}
	else
	{
		for(register int i=0;i<code.length();i++)
		{
			if(code[i]!=edoc[edoc.length()-1-i])
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
}