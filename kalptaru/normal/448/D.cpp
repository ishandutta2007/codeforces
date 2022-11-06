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
		ll n,m,k;
		cin>>n>>m>>k;
		ll l=1,r=n*m,o,c;
		ll mid;
		while(l<r)
		{
			c=0;
			mid=(l+r+1)/2;
			FOR(i,1,n+1)
			{
				o=(mid-1)/i;
				c+=min(m,o);
			}
			if(c>=k)
			{
				r=mid-1;
			}
			else
			{
				l=mid;
			}
		}
		cout<<l;
	}
	return 0;
}