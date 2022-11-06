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
		ll n,x,xo=0;
		cin>>n>>x;
		ll p=524288;
		
		if(n==1)
		{
			cout<<"YES\n";
			cout<<x;
			return 0;
		}
		if(n==2)
		{
			if(x==0)
			cout<<"NO";
			else
			{
				cout<<"YES\n0 "<<x;
			}
			return 0;
		}
		cout<<"YES\n";
		FOR(i,2,n-1)
		{
			xo=xo^i;
			cout<<i<<' ';
		}
		if(xo==x)
		{
			cout<<1<<' '<<p+2<<' '<<p+3;
		}
		else
		{
			cout<<0<<' '<<(p^xo)<<' '<<(p^x);
		}
	}
	return 0;
}