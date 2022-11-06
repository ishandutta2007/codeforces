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
bool che(pair<long double,long double> a,pair<long double,long double> b)
{
	return (a.second/a.first)<(b.second/b.first);
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
		int n;
		long double p;
		cin>>n>>p;
		cout<<fixed<<setprecision(10);
		long double c=0, s=0,ans=0,t,le;
		pair<long double,long double> a[n];
		FOR(i,0,n)
		{
			cin>>a[i].first>>a[i].second;
		}
		sort(a,a+n,che);
		ans=a[0].second/a[0].first;
		le=p*ans;
		FOR(i,1,n)
		{
			t=a[i].second/a[i].first;
			c+=a[i-1].first;
			if((c*(t-ans))<=(p*(t-ans)+le))
			{
				le+=(p*(t-ans));
				le-=(c*(t-ans));
				ans=t;
			}
			else
			{
				ans=ans+(le/(c-p));
				cout<<ans;
				return 0;
			}
		}
		c+=a[n-1].first;
		if(p>=c)
		cout<<-1;
		else
		cout<<ans+(le/(c-p));
	}
	return 0;
}