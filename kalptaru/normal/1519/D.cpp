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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("java2016.in", "r", stdin);
    // freopen("java2016.out", "w", stdout);
    // ll gtest=0;
    // spre
	ll test=1;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n],b[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		ll o=0,m;
		FOR(i,0,n)
		{
			cin>>b[i];
			o+=a[i]*b[i];
		}
		m=o;
		ll dp[n][n];
		memset(dp,0,sizeof(dp));
		FOR(i,0,n)
		{
			dp[0][i]=o;
		}
		FOR(i,0,n-1)
		{
			dp[1][i]=o-a[i]*b[i]-a[i+1]*b[i+1]+a[i]*b[i+1]+b[i]*a[i+1];
			m=max(m,dp[1][i]);
		}
		FOR(i,2,n)
		{
			FOR(j,0,n-i)
			{
				dp[i][j]=dp[i-2][j+1]-a[j]*b[j]-a[j+i]*b[j+i]+a[j]*b[j+i]+a[j+i]*b[j];
				m=max(dp[i][j],m);
			}
		}
		cout<<m;

	}
	return 0;
}