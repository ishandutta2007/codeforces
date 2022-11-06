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
const ll mod=998244353;
// ll mod=1000000007;
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
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll t[n],x[n];
		int ans=0;
		cin>>t[0]>>x[0];
		ll p=0,d=x[0];
		FOR(i,1,n)
		{
			cin>>t[i]>>x[i];
			// cout<<p<<' '<<d<<'\n';
			if((t[i]-t[i-1])>=abs(d-p))
			{
				if(((x[i-1]-d)*(p-x[i-1]))>=0)
				{
					ans++;
				}
				p=d;
				d=x[i];
			}
			else
			{
				if(d>p)
				{
					ll l=p+(t[i]-t[i-1]);
					if(((x[i-1]-l)*(p-x[i-1]))>=0)
					{
						ans++;
					}
					p=l;
				}
				else
				{
					ll l=p-(t[i]-t[i-1]);
					if(((x[i-1]-l)*(p-x[i-1]))>=0)
					{
						ans++;
					}
					p=l;
				}
			}
		}
		// cout<<p<<' '<<d<<'\n';
		if(((x[n-1]-d)*(p-x[n-1]))>=0)
		{
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}