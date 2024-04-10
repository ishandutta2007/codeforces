#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
ll mod=1e9+7;
ll INF=1e18;
ll po(ll a,ll b){
	ll re=1;  
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
ll dp[505][505][12];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // ll gtest=0;
    // spre
	ll test=1;
	// cin>>test;
	while(test--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		ll a[n][m];
		ll b[n][m];
		FOR(i,0,n)
		{
			FOR(j,0,m-1)
			{
				cin>>a[i][j];
			}
		}
		FOR(i,0,n-1)
		{
			FOR(j,0,m)
			{
				cin>>b[i][j];
			}
		}
		if((k%2)!=0)
		{
			FOR(i,0,n)
			{
				FOR(j,0,m)
				{
					cout<<"-1 ";
				}
				cout<<'\n';
			}
			return 0;
		}
		k/=2;
		FOR(t,1,k+1)
		{
			FOR(i,0,n)
			{
				FOR(j,0,m)
				{
					ll p;
					dp[i][j][t]=INF;
					if(i>0)
					{
						p=2*b[i-1][j]+min(dp[i-1][j][t-1],dp[i][j][t-1]);
						dp[i][j][t]=min(dp[i][j][t],p);
					}
					if(i<(n-1))
					{
						p=2*b[i][j]+min(dp[i+1][j][t-1],dp[i][j][t-1]);
						dp[i][j][t]=min(dp[i][j][t],p);
					}

					if(j>0)
					{
						p=2*a[i][j-1]+min(dp[i][j-1][t-1],dp[i][j][t-1]);
						dp[i][j][t]=min(dp[i][j][t],p);
					}
					if(j<(m-1))
					{
						p=2*a[i][j]+min(dp[i][j+1][t-1],dp[i][j][t-1]);
						dp[i][j][t]=min(dp[i][j][t],p);
					}
				}
			}
		}

		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				cout<<dp[i][j][k]<<' ';
			}
			cout<<'\n';
		}
	}

	return 0;
}