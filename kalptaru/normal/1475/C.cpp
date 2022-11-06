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
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=985661441;
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
ll c[200005],d[200005];
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
	// spre
	while(test--)
	{
		ll a,b,k;
		cin>>a>>b>>k;
		ll u,v,p[k],q[k];
		ll ans=(k*(k-1))/2;
		FOR(i,0,k)
		{
			cin>>p[i];
		}
		FOR(i,0,k)
		{
			cin>>v;
			u=p[i];
			q[i]=v;
			ans+=(c[u]*(c[u]-1))/2;
			c[u]++;
			ans-=(c[u]*(c[u]-1))/2;
			ans+=(d[v]*(d[v]-1))/2;
			d[v]++;
			ans-=(d[v]*(d[v]-1))/2;
			// cout<<i<<' '<<ans<<'\n';
			
		}
		cout<<ans<<'\n';
		FOR(i,0,k)
		{
			c[p[i]]=0;
			d[q[i]]=0;
		}
	}
	return 0;
}