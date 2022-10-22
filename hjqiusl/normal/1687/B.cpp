// Lynkcat.
// Problem: B. Railway System
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/B?f0a28=1
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
#define N  200005
using namespace std;
int n,m,vis[N],p[N],val[N],ans;
int qry()
{
	string st;
	cout<<"? ";
	for (int i=1;i<=m;i++)	
		st+=char(vis[i]+'0');
	cout<<st<<endl;
	int res;
	cin>>res;
	return res;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		vis[i]=1;
		val[i]=qry();
		vis[i]=0;
		p[i]=i;
	}
	sort(p+1,p+m+1,[&](int x,int y)
	{
		return val[x]<val[y];
	});
	int now=0;
	for (int i=1;i<=m;i++)
	{
		int u=p[i];
		vis[u]=1;
		int v=qry();
		if (v-now==val[u]) 
		{
			ans+=val[u];
			now=v;
		}
		else vis[u]=0;
	}
	cout<<"! "<<ans<<endl;
			
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}