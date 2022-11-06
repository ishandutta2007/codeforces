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
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
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
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ll ans=0;
		ll m,p,q,r,s;
		FOR(i,c,d+1)
		{
			p=i-b+1;
			m=c-b+1;
			if(p>b)
			{
				m-=(p-b);
				p=b;
			}
			if(m<1)
			continue;
			if(p>=a)
			{
				q=max(p-m,a);
				r=(b-p);
				s=b-q;
				ans-=((r+1)*r)/2-((s+1)*s)/2;
				m-=(p-q);
			}
			if(m<1)
			continue;
			ans+=(m*(b-a+1));
//			cout<<ans<<' ';
		}
		cout<<ans;
	}
	return 0;
}