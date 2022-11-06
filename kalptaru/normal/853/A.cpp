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
	ll res=1;
	while(b)
	{
		if(b%2==1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
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
//	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		pair<ll,int> c[n];
		FOR(i,0,n)
		{
			cin>>c[i].first;
			c[i].second=i;
		}
		sort(c,c+n);
		bool d[n+k]={0};
		int j=k;
		int t[n];
		ll ans=0;
		FOR(i,0,n)
		{
			while(d[j])
			j++;
			int p=max(j,c[n-i-1].second);
			if(p==j)
			{
				ans+=((j-c[n-i-1].second)*c[n-i-1].first);
			}
			d[p]=1;
			t[c[n-i-1].second]=p+1;
		}
		cout<<ans<<'\n';
		FOR(i,0,n)
		cout<<t[i]<<' ';
	}
	return 0;
}