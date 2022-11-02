#include<bits/stdc++.h>
using namespace std;
string a,b,c; 
int main()
{
	cin>>a>>b;
	for(register int i=0;i<a.length();i++)
	{
		if(a[i]==b[i])
		{
			c.append("0");
		}
		else
		{
			c.append("1");
		}
	}
	cout<<c;
}