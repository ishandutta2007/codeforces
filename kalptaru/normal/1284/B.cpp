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
ll mi[1000001];
ll ma[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector< pair<ll,ll> > pa;
		ll c=n;
		FOR(i,0,n)
		{
			ll l,p=1000001,g,m1=0,m2=1000001;
			bool f=0;
			cin>>l;
			FOR(j,0,l)
			{
				cin>>g;
				m1=max(m1,g);
				m2=min(m2,g);
				if(g>p)f=1;
				p=g;
			}
			if(f)
			{
				c--;
			}
			else
			{
				mi[m2]++;
				pa.pb(mp(m2,m1));
			}
		}
		FOR(i,1,1000001)
		{
			mi[i]+=mi[i-1];
		}
		ll ans=n*n-c*c;
		FOR(i,0,c)
		{
			ans+=mi[pa[i].second-1];
//			if(pa[i].first==pa[i].second)ans++;
		}
		cout<<ans;
	}
	return 0;
}