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
		int n,k;
		cin>>n>>k;
		int a[n];
		FOR(i,0,n)
		cin>>a[i];
		int c[2*k+2]={0};
		int ans=n;
		FOR(i,0,n/2)
		{
			c[min(a[i],a[n-i-1])+1]++;
			c[max(a[i],a[n-i-1])+k+1]--;
		}
		FOR(i,2,2*k+1)
		{
			c[i]+=c[i-1];
		}
		FOR(i,0,n/2)
		c[a[i]+a[n-i-1]]++;
		FOR(i,2,2*k+1)
		{
			ans=min(ans,n-c[i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}