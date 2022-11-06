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
ll po(ll a,ll b){
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			// re%=mod;
		}
		a=(a*a);
		// a%=mod;
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
		ll p,q;
		cin>>p>>q;
		if((p%q)!=0)
		{
			cout<<p<<'\n';
			continue;
		}
		ll o=q;
		vector< pair<int,int> > f;
		for(ll i=2;(i*i)<=q;i++)
		{
			int c=0;
			while((o%i)==0)
			{
				c++;
				o/=i;
			}
			if(c>0)
			{
				f.pb(mp(i,c));
			}
			if(o==1)
				break;
		}
		if(o>1)
		{
			f.pb(mp(o,1));
		}
		ll x=1;
		int s=f.size();
		FOR(i,0,s)
		{
			o=p;
			while((o%f[i].first)==0)
			{
				o/=f[i].first;
			}
			o*=po(f[i].first,f[i].second-1);
			x=max(x,o);
		}
		cout<<x<<'\n';
	}
	return 0;
}