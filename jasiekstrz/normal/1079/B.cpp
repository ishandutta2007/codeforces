#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,a,b,l,i,j,k;
	string s;
	cin>>s;
	n=s.size();
	a=(n+19)/20;
	b=(n+a-1)/a;
	l=a*b-n;
	k=0;
	cout<<a<<" "<<b<<"\n";
	for(i=1;i<=l;i++)
	{
		cout<<"*";
		for(j=2;j<=b;j++)
		{
			cout<<s[k];
			k++;
		}
		cout<<"\n";
	}
	for(i=l+1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			cout<<s[k];
			k++;
		}
		cout<<"\n";
	}
	return 0;
}