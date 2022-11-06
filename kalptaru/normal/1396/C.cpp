#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include<vector>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll n,r1,r2,r3,d;
		cin>>n>>r1>>r2>>r3>>d;
		ll a[n],f[n],s[n],fa,ans,dp[n+1];
		FOR(i,0,n)
		{
			cin>>a[i];
			f[i]=min((a[i]+2)*r1,r2+r1);
			s[i]=a[i]*r1+r3;
		}
		dp[0]=-d;
		dp[1]=s[0];
		FOR(i,1,n)
		{
			dp[i+1]=min(min(dp[i]+d+s[i],dp[i]+3*d+f[i]),dp[i-1]+4*d+f[i]+f[i-1]);
			if(i==(n-1))
			dp[i+1]=min(dp[i+1],dp[i-1]+3*d+s[i]+f[i-1]);
		}
		cout<<dp[n];
	}
	return 0;
}