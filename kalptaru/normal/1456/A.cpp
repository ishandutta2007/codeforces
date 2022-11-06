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
	int test=1;
	cin>>test;
	while(test--)
	{
		ll n,p,k,x,y;
		cin>>n>>p>>k;
		string s;
		cin>>s;
		cin>>x>>y;
		ll dp[n]={0};
		FORD(i,n,p-1)
		{
			if(s[i]=='0')
				dp[i]=x;
			if((n-i)>k)
			{
				dp[i]+=dp[i+k];
			}
		}
		ll ans=dp[p-1];
		FOR(i,p,n)
		{
			ans=min(ans,dp[i]+(i-p+1)*y);
		}
		cout<<ans<<'\n';
	}
	return 0;
}