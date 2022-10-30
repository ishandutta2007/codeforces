#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str;
ll res;
int main()
{
	cin>>str;
	for(register int i=0;i<str.length();i++)
	{
		if(str[i]=='4'||str[i]=='7')
		{
			res++;
		}
	}
	res==4||res==7?cout<<"YES":cout<<"NO";
}