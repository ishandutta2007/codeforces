// Lynkcat.
// Problem: D. Permutation Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/D
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
int n,a[N],vis[N],ans[N];
int col[N],ru[N];
poly G[N];
int pos[N];
void BellaKira()
{
	map<int,int>Mp;
	int tot=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],vis[i]=ans[i]=pos[i]=ru[i]=0;
	for (int i=1;i<=n;i++)
	{
		if (Mp.count(a[i])) col[i]=Mp[a[i]];
		else  col[i]=++tot,Mp[a[i]]=tot;
		G[col[i]].push_back(i);
	}
	int res=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=0&&a[i]!=n+1)
		{
			vis[col[a[i]]]=col[i];
			ru[col[i]]++;
			pos[col[a[i]]]=a[i];
			// cout<<"?"<<
		}
		if (a[i]>i) res=max(res,i);
	}
	int rt=0;
	for (int i=1;i<=tot;i++)
		if (!ru[i])
		{
			rt=i;
		}
	int dfn=0;
	int x=0,y=0;
	// cout<<"?"<<pos[3]<<endl;
	while (rt)
	{
		for (auto u:G[rt])
			if (pos[rt]!=u)
			{
				ans[++dfn]=u;
			}
		for (auto u:G[rt])
			if (pos[rt]==u)
			{
				ans[++dfn]=u;
			}
		rt=vis[rt];
	}
	cout<<res<<'\n';
	for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
	for (int i=1;i<=tot;i++) poly().swap(G[i]);
			
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