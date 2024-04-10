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
		int n,p;
		cin>>n>>p;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		sort(a,a+n);
		ll r=1,l=mod;
		FOR(i,0,n)
		{
			r=max(r,a[i]-i);
			if((i+p-1)<n)
			{
				l=min(l,a[i+p-1]-i-1);
			}
		}
		if(l<r)
		{
			cout<<0;
			break;
		}
		cout<<l-r+1<<'\n';
		FOR(i,r,l+1)
		cout<<i<<' ';
	}
	return 0;
}