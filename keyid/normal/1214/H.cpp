#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=200005;

int n,k,c[MAXN],d[MAXN],fa[MAXN],p[MAXN],dp[MAXN][3];
vector <int> G[MAXN];

void dfs0(int u,int fa)
{
	for (int v:G[u])
		if (v!=fa)
		{
			c[v]=c[u]^1;
			dfs0(v,u);
		}
}

void dfs1(int u)
{
	for (int v:G[u])
		if (v!=fa[u])
		{
			fa[v]=u;
			d[v]=d[u]+1;
			dfs1(v);
		}
}

inline void update(int dp[3],int v)
{
	if (v>dp[0])
	{
		dp[2]=dp[1];
		dp[1]=dp[0];
		dp[0]=v;
	}
	else if (v>dp[1])
	{
		dp[2]=dp[1];
		dp[1]=v;
	}
	else if (v>dp[2])
		dp[2]=v;
}

void dfs2(int u,int fa)
{
	for (int v:G[u])
		if (v!=fa)
		{
			dfs2(v,u);
			update(dp[u],dp[v][0]+1);
		}
}

void dfs3(int u,int fa,int up)
{
	for (int v:G[u])
		if (v!=fa)
		{
			int d=dp[u][0]!=dp[v][0]+1?dp[u][0]:dp[u][1];
			d=max(d,up)+1;
			dfs3(v,u,d);
		}
	update(dp[u],up);
}

void dfs4(int u,int fa)
{
	c[u]=(c[fa]+1)%k;
	for (int v:G[u])
		if (v!=fa)
			dfs4(v,u);
}

void dfs5(int u,int fa)
{
	c[u]=(c[fa]+k-1)%k;
	for (int v:G[u])
		if (v!=fa)
			dfs5(v,u);
}

bool solve()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	if (k==2)
		dfs0(1,0);
	else
	{
		dfs2(1,0);
		dfs3(1,0,0);
		for (int i=1;i<=n;i++)
			if (dp[i][2]&&dp[i][1]+dp[i][2]+1>=k)
				return false;
		fa[1]=0;
		dfs1(1);
		int p1=1;
		for (int i=2;i<=n;i++)
			if (d[i]>d[p1])
				p1=i;
		d[p1]=0;
		fa[p1]=0;
		dfs1(p1);
		int p2=p1;
		for (int i=1;i<=n;i++)
			if (d[i]>d[p2])
				p2=i;
		if (d[p2]+1>=k)
		{
			for (int v=p2;;v=fa[v])
			{
				p[d[v]]=v;
				if (v==p1)
					break;
			}
			int r=p[(d[p2]+1)/2];
			for (int v:G[r])
				if (v!=fa[r])
					dfs4(v,r);
				else
					dfs5(v,r);
		}
	}
	return true;
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int ans=solve();
	if (ans)
	{
		puts("Yes");
		for (int i=1;i<=n;i++)
			printf("%d ",c[i]+1);
	}
	else
		puts("No");
	return 0;
}