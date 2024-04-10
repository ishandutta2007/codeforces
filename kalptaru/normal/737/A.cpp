#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
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
		ll n,k,s,t;
		cin>>n>>k>>s>>t;
		vector<ll> pt;
		map<ll,ll> tpl,td;
		ll c[n],v[n];
		FOR(i,0,n)
		{
			cin>>c[i]>>v[i];
			pt.pb(v[i]);
		}
		ll g[k+1];
		FOR(i,0,k)
		cin>>g[i];
		g[k]=s;
		sort(g,g+k);
		ll di[k+1];
		ll p=0;
		FOR(i,0,k+1)
		{
			di[i]=g[i]-p;
			p=g[i];
		}
		ll ma=0;
		FOR(i,0,k+1)
		{
			if(di[i]==0)
			continue;
			ma=max(ma,di[i]);
			pt.pb(di[i]);
			pt.pb(2*di[i]);
			tpl[di[i]]+=2*di[i];
			td[di[i]]++;
			td[2*di[i]]--;
		}
		sort(pt.begin(),pt.end());
		ll tim=0,tde=0,nc=INF;
		p=0;
		FOR(i,0,pt.size())
		{
			if(pt[i]==p)
			continue;
			tim+=tpl[pt[i]];
			tim-=(tde*(pt[i]-p));
			if(tim<=t && pt[i]>=ma)
			{
				nc=pt[i];
				break;
			}
			tde+=td[pt[i]];
			p=pt[i];
		}
		ll mi=INF;
		FOR(i,0,n)
		{
			if(v[i]>=nc)
			{
				mi=min(mi,c[i]);
			}
		}
		if(mi==INF)
		{
			cout<<-1;
		}
		else
		cout<<mi;
	}
	return 0;
}