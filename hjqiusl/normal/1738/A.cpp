// Lynkcat.
// Problem: A. Glory Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/0
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
#define N 100005
using namespace std;
int n,a[N],b[N];
poly G[3];
void BellaKira()
{
	int ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]++;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
		G[a[i]].push_back(b[i]);
	}
	int x=min(G[1].size(),G[2].size());
	if (G[1].size()==G[2].size())
	{
		int ans=0;
		int mn=b[1];
		for (auto u:G[1]) ans+=u*2,mn=min(mn,u);
		for (auto u:G[2]) ans+=u*2,mn=min(mn,u);
		cout<<ans-mn<<'\n';
	} else
	{
		sort(G[1].begin(),G[1].end(),greater<int>());
		sort(G[2].begin(),G[2].end(),greater<int>());
		for (auto u:G[1]) ans+=u;
		for (auto u:G[2]) ans+=u;
		for (int i=0;i<x;i++) ans+=G[1][i];
		for (int i=0;i<x;i++) ans+=G[2][i];
		cout<<ans<<'\n';
	}
	poly().swap(G[1]);
	poly().swap(G[2]);
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}