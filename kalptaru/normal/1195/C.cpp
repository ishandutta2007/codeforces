#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,p=0;
	cin>>n;
	ll h[2][n],u=0,d=0,ans=0;
	for(int i=0;i<n;i++)
	cin>>h[0][i];
	for(int i=0;i<n;i++)
	cin>>h[1][i];
	for(int i=0;i<n;i++)
	{
		if(u+h[(i-p)%2][i]<=d)
		{
			ans+=d;
			if((i-p)%2==1)
			{u=0;d=h[0][i];}
			else
			{u=h[1][i];d=0;}
			p=i+1;
		}
		else if(d+h[(i-p+1)%2][i]<=u)
		{
			ans+=u;
			if((i-p)%2==0)
			{u=0;d=h[0][i];}
			else
			{u=h[1][i];d=0;}
			p=i+1;
		}
		else
		{
			u+=h[(i-p)%2][i];
			d+=h[(i-p+1)%2][i];
		}
	}
	ans+=(max(u,d));
	cout<<ans;
	return 0;
}