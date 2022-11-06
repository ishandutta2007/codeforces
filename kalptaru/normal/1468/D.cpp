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
const ll mod=1000000007;
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	ll test=1;
	cin>>test;
	while(test--)
	{
		ll n,m,a,b;
		cin>>n>>m>>a>>b;
		if(a>b)
		{
			a=n-a+1;
			b=n-b+1;
		}
		a=b-a-1;
		b--;
		ll s[m];
		FOR(i,0,m)
		{
			cin>>s[i];
		}
		sort(s,s+m);
		int ans=0;
		FORD(i,m,0)
		{
			if(a==0)
				break;
			if(s[i]<b)
			{
				// cout<<s[i]<<' '<<b<<'\n';
				ans++;
				a--;
				b--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}