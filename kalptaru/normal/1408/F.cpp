#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e9;
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
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int o=1;
		while(o<n)
		{
			o*=2;
		}
		o=o/2;
		vector<pair<int,int> > an;
		for(int i=2;i<=o;i*=2)
		{
			for(int j=1;j<=o;j+=i)
			{
				for(int k=0;k<(i/2);k++)
				{
					an.pb(mp(j+k,j+k+i/2));
				}
			}
		}
		if(o!=n)
		{
			int u=n-o;
			for(int i=2;i<=o;i*=2)
			{
				for(int j=1;j<=o;j+=i)
				{
					for(int k=0;k<(i/2);k++)
					{
						an.pb(mp(j+k+u,j+k+u+i/2));
					}
				}
			}
		}
		int si=an.size();
		cout<<si<<'\n';
		FOR(i,0,si)
		{
			cout<<an[i].first<<' '<<an[i].second<<'\n';
		}
	}
	return 0;
}