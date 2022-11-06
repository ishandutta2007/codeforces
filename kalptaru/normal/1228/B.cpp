#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll inf=1000000000000000002;
ll mod=1000000007;
int g[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int h,w;
		cin>>h>>w;
		int r,c;
		ll ans=1;
		FOR(i,0,h)
		{
			cin>>r;
			FOR(j,0,r)
			{
				g[i][j]=2;
			}
			g[i][r]=1;
		}
		FOR(i,0,w)
		{
			cin>>c;
			FOR(j,0,c)
			{
				if(g[j][i]==1)
				{
					cout<<0;
					return 0;
				}
				else
				g[j][i]=2;
			}
			if(g[c][i]==2)
			{
				cout<<0;
				return 0;
			}
			else
			g[c][i]=1;
		}
		FOR(i,0,h)
		{
			FOR(j,0,w)
			{
				if(g[i][j]==0)
				ans=((ans*2)%mod);
			}
		}
		cout<<ans;
	}
	return 0;
}