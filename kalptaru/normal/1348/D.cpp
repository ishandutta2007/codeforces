#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=1000000007;
ll mod=67280421310721;
//ll mod=998244353;
//ll mod=163577857;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a)%mod;
		}
		a=(a*a)%mod;
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
	cin>>test;
	while(test--)
	{
		int d=0;
		ll n,v,nn,m=1;
		cin>>n;
		if(n==2)
		{
			cout<<1<<'\n'<<0<<'\n';
			continue;
		}
		if(n==3)
		{
			cout<<1<<'\n'<<1<<'\n';
			continue;
		}
		nn=n-1;
		n-=m;
		while(n>0)
		{
			d++;
			m<<=1;
			n-=m;
		}
//		d--;
		cout<<d<<'\n';
		
		m=1;
		FOR(i,0,d-2)
		{
			cout<<m<<' ';
			m<<=1;
			nn-=m;
		}
		if(nn>=(4*m))
		{
			cout<<m<<' ';
			m<<=1;
			nn-=m;
			cout<<nn-m;
		}
		else
		{
			v=nn/2;
			cout<<v-m<<' '<<nn%2;
		}
		cout<<'\n';
	}
	return 0;
}