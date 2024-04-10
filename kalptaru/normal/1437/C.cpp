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
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e9;
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
	return re;}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int t[n];
		FOR(i,0,n)
		{
			cin>>t[i];
		}
		sort(t,t+n);
		int dp[n][2*n];
		FOR(i,0,n)
		{
			FOR(j,0,2*n)
			{
				dp[i][j]=INF;
			}
		}
		FOR(i,0,n)
		{
			int u=INF;
			FOR(j,1,2*n)
			{
				if(i==0)
				{
					dp[i][j]=abs(t[i]-j);
				}
				else
				{
					u=min(u,dp[i-1][j-1]);
					dp[i][j]=u+abs(t[i]-j);
				}
			}
		}
		// FOR(i,0,n)
		// {
		// 	FOR(j,0,2*n)
		// 	{
		// 		cout<<dp[i][j]<<' ';
		// 	}
		// 	cout<<'\n';
		// }
		int ans=INF;
		FOR(i,1,2*n)
		{
			ans=min(ans,dp[n-1][i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}