#include<bits/stdc++.h>
using namespace std;
string str;
char org,rep;
int length,l,r,op;
int main()
{
	cin>>length>>op>>str;
	for(register int i=0;i<op;i++)
	{
		cin>>l>>r>>org>>rep; 
		for(register int i=l;i<=r;i++)
		{
			if(str[i-1]==org)
			{
				str[i-1]=rep;
			}
		}
	}
	cout<<str;
}