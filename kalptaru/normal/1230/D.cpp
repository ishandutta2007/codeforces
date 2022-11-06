#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll inf=1000000000000000002;
bool c[7001][7001];
int cnt[7001];
bool g[7001];
int n;
void rem(int i)
{
	g[i]=0;
	FOR(j,0,n)
	{
		if(g[j] && i!=j)
		{
			if(c[j][i]==1)
			{
				cnt[j]--;
				c[j][i]=0;
				if(cnt[j]==0)
				{
					rem(j);
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		cin>>n;
		ll a[n],b[n];
		FOR(i,0,n)
		{cin>>a[i];g[i]=1;}
		ll ans=0;
		FOR(i,0,n)
		cin>>b[i];
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				if(i!=j)
				{
					if((a[i]&a[j])==a[i])
					{
						c[i][j]=1;
						cnt[i]++;
					}
				}
			}
		}
		FOR(i,0,n)
		{
			if(cnt[i]==0 && g[i])
			{
				rem(i);
			}
		}
		FOR(i,0,n)
		{
			if(g[i])
			ans+=b[i];
		}
		cout<<ans;
	}
	return 0;
}