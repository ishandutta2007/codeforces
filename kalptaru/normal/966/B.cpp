#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll mod=163577857;
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
		int n;
		ll x1,x2;
		cin>>n>>x1>>x2;
		pair<ll,int> c[n];
		FOR(i,0,n)
		{
			cin>>c[i].first;
			c[i].second=i;
		}
		sort(c,c+n);
		int in=-1,k=-1;
		FOR(i,1,n+1)
		{
			if(((x1-1)/i+1)<=c[n-i].first)
			{
				in=i;
				break;
			}
		}
		if(in!=-1)
		{
			FOR(i,in+1,n+1)
			{
				if(((x2-1)/(i-in)+1)<=c[n-i].first)
				{
					k=i;
					break;
				}
			}
		}
		if(k!=-1)
		{
			cout<<"Yes"<<'\n';
			cout<<in<<' '<<k-in<<'\n';
			FOR(i,1,in+1)
			cout<<c[n-i].second+1<<' ';
			cout<<'\n';
			FOR(i,in+1,k+1)
			cout<<c[n-i].second+1<<' ';
			return 0;
		}
		swap(x1,x2);
		in=-1,k=-1;
		FOR(i,1,n+1)
		{
			if(((x1-1)/i+1)<=c[n-i].first)
			{
				in=i;
				break;
			}
		}
		if(in!=-1)
		{
			FOR(i,in+1,n+1)
			{
				if(((x2-1)/(i-in)+1)<=c[n-i].first)
				{
					k=i;
					break;
				}
			}
		}
		if(k!=-1)
		{
			cout<<"Yes"<<'\n';
			cout<<k-in<<' '<<in<<'\n';
			FOR(i,in+1,k+1)
			cout<<c[n-i].second+1<<' ';
			cout<<'\n';
			FOR(i,1,in+1)
			cout<<c[n-i].second+1<<' ';
			return 0;
		}
		cout<<"No";
	}
	return 0;
}