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
		int n,k,a;
		cin>>n>>k;
		bool f[n]={0};
		FOR(i,0,n)
		{
			cin>>a;
			f[a-1]=1;
//			cout<<a<<' ';
		}
		int c=0;
		FOR(i,0,n)
		{
			if(f[i]==1)
			c++;
		}
		if(c>k)
		{
//			cout<<c<<' '<<k;
			cout<<"-1\n";
			continue;
		}
		int u=0;
		while(c<k)
		{
			if(f[u]==0)
			{
				c++;
				f[u]=1;
			}
			u++;
		}
		cout<<(n*k)<<'\n';
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				if(f[j])
				cout<<j+1<<' ';
			}
		}
		cout<<'\n';
//		cout<<"---------";
	}
	return 0;
}