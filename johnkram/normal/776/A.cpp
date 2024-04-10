#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s0,s1,s2,s3;
int n;
int main()
{
	cin>>s0>>s1>>n;
	for(cout<<s0<<' '<<s1<<endl;n--;cout<<s0<<' '<<s1<<endl)
	{
		cin>>s2>>s3;
		if(s0==s2)s0=s3;
		else s1=s3;
	}
	return 0;
}