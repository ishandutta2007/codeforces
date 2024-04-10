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
ll o[10000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		FOR(i,2,10000001)
		{
			if(o[i]!=0)
			continue;
			for(int j=2*i;j<10000001;j+=i)
			{
				if(o[j]==0)
				o[j]=i;
			}
		}
		int n=0;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		pair<int,int> ans[n];
		FOR(i,0,n)
		{
			if(o[a[i]]==0)
			{
				ans[i]=mp(-1,-1);
				continue;
			}
			int u=a[i];
//			cout<<o[u]<<' ';
			while(a[i]%o[u]==0)
			{
				a[i]/=o[u];
			}
			if(a[i]>1)
			{
				ans[i]=mp(a[i],u/a[i]);
			}
			else
			ans[i]=mp(-1,-1);
		}
		FOR(i,0,n)
		cout<<ans[i].first<<' ';
		cout<<'\n';
		FOR(i,0,n)
		cout<<ans[i].second<<' ';
	}
	return 0;
}