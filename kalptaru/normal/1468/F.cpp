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
		int n;
		cin>>n;
		ll x,y,u,v,o,g;
		// cin>>x>>y>>u>>v;
		map<pair<pair<ll,ll>,ll> ,ll> al;
		ll ans=0;
		FOR(i,0,n)
		{
			cin>>x>>y>>u>>v;
			x-=u;
			y-=v;
			o=x*x+y*y;
			if(x==0)
			{
				g=__gcd(y*y,o);
			}
			else if(y==0)
			{
				g=__gcd(x*x,o);
			}
			else
			{
				g=__gcd(x*x,y*y);
				g=__gcd(g,o);
			}
			x=(x*abs(x))/g;
			y=(y*abs(y))/g;
			o/=g;

			ans+=al[mp(mp(x,y),o)];
			al[mp(mp(-x,-y),o)]++;
			// cout<<x<<' '<<y<<' '<<o<<' '<<g<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}