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
//	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		ll a[n],b[n],sa=0,sb=0;
		FOR(i,0,n)
		{
			cin>>a[i]>>b[i];
			sa+=a[i];
			sb+=b[i];
		}
		int ra=sa%k,rb=sb%k;
		if((ra+rb)<k)
		{
			cout<<(sa+sb)/k;
			return 0;
		}
		bitset<505> pa=0,tem=0;
		bool rtem;
		pa[ra]=1;
		FOR(i,0,n)
		{
			if((a[i]+b[i])>=k)
			{
				tem=pa;
				FOR(j,1,k)
				{
					rtem=tem[0];
					tem>>=1;
					tem[k-1]=rtem;
					if((a[i]>=j) &&(b[i]>=(k-j)))
					{
						pa=pa|tem;
					}
//					cout<<pa<<'\n';
				}
//				cout<<'\n';
			}
		}
		int h=ra+rb-k;
		bool ans=0;
		FOR(i,0,h+1)
		{
			if(pa[i]==1)
			ans=1;
		}
		if(ans)
		{
			cout<<(sa+sb)/k;
		}
		else
		{
			cout<<((sa+sb)/k)-1;
		}
	}
	return 0;
}