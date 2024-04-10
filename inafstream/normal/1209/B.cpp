#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

const int mod=240;

int n,a[245],x,y;
string st;

int main()
{
	int i,j;
	
	cin>>n>>st;
	st=" "+st; 
	rep(i,n)
	{
		cin>>x>>y;
		for (j=0;j<mod;j++)
		{
			int t=st[i]-'0';
			if (y<=j&&(j-y)%(x+x)<x) t^=1;
			a[j]+=t;
		}
	}
	
	int ans=0;
	for (i=0;i<mod;i++)
	{
		ans=max(ans,a[i]);
	}
	
	cout<<ans<<endl;
	return 0;
}