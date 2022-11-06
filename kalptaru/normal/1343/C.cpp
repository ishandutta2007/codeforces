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
		}
		a=(a*a);
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
		ll n;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		ll ans=0;
		ll m=a[0];
		bool f=1;
		if(a[0]<0)
		f=0;
		FOR(i,0,n)
		{
			if(f)
			{
				if(a[i]<0)
				{
					ans+=m;
					m=a[i];
					f=0;
				}
				else
				{
					m=max(m,a[i]);
				}
			}
			else
			{
				if(a[i]>0)
				{
					ans+=m;
					m=a[i];
					f=1;
				}
				else
				{
					m=max(m,a[i]);
				}
			}
		}
		ans+=m;
		cout<<ans<<'\n';
	}
	return 0;
}