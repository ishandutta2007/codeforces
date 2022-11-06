#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll mi3=499122177;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll res=1;
//	a=a%mod3;
	while(b>0)
	{
		if(b%2==1)
		{
			res*=a;
//			res%=mod3;
		}
		a*=a;
//		a%=mod3;
		b>>=1;
	}
	return res;
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
		ll d,m;
		cin>>d>>m;
		int l=log2(d);
//		cout<<l;
		ll p[l+1];
		ll o=1;
		FOR(i,0,l)
		{
			p[i]=o;
			o*=2;
			o%=m;
		}
		p[l]=(d-po(2,l)+1)%m;
		ll ans=0;
		FOR(i,0,l+1)
		{
			ans=(((ans+1)*(p[i]+1))-1)%m;
		}
		cout<<ans<<'\n';
	}
	return 0;
}