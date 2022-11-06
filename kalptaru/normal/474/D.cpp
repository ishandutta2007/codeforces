#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll powm(ll a,ll b)
{
	ll r=a%mod,ans=1;
	while(b>0)
	{
		if(b%2==1)
		ans=(ans*r)%mod;
		r=(r*r)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1,k;
	cin>>t>>k;
	ll dp[100001];
	dp[0]=1;
	FOR(i,1,100001)
	{
		dp[i]=dp[i-1];
		if(i>=k)
		dp[i]=(dp[i]+dp[i-k])%mod;
	}
	FOR(i,1,100001)
	{
		dp[i]+=dp[i-1];
		if(dp[i]>=mod) dp[i]-=mod;
	}
	while ( t-- ) 
	{
		int a,b;
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1]+mod)%mod<<'\n';
	}
	return 0;
}