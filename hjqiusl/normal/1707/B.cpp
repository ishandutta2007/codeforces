// Lynkcat.
// Problem: B. Difference Array
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 500005 
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	int x=0;
	poly g;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		g.push_back(a[i]);
	}
	int tim=n-1;
	while (tim--)
	{
		if (g[g.size()-2]==0) break;
		int now=0;
		for (int j=(int)g.size()-1;j>=0;j--)
			if (g[j]==0)
			{
				now=j;
				break;
			}
		for(int i=now;i+1<g.size();++i)
		{
			g[i]=g[i+1]-g[i];
		}
		g.pop_back();
		sort(g.begin()+now,g.end());
		// for (auto u:g) cout<<u<<",";
		// cout<<endl;
	}
	cout<<g.back()<<'\n';
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}