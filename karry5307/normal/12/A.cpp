#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str,temp;
int main()
{
	for(register int i=0;i<3;i++)
	{
		cin>>temp;
		str+=temp;
	}
	for(register int i=0;i<=4;i++)
	{
		if(str[i]!=str[8-i])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}