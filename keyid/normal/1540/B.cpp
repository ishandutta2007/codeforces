#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=205,MOD=1000000007,inv2=(MOD+1)/2;

int dp[MAXN][MAXN],lca[MAXN][MAXN],fa[MAXN],dep[MAXN];
vector<int> G[MAXN];

int get_inv(int x)
{
	if (x==1)
		return 1;
	return (LL)(MOD-MOD/x)*get_inv(MOD%x)%MOD;
}

void dfs(int u)
{
	for (int v:G[u])
		if (v!=fa[u])
		{
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs(v);
		}
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
		dp[0][i]=1;
	for (int i=1;i<n;i++)
		for (int j=1;j<n;j++)
			dp[i][j]=(LL)(dp[i-1][j]+dp[i][j-1])*inv2%MOD;
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		fa[i]=0;
		dep[i]=0;
		dfs(i);
		int id[MAXN];
		for (int j=1;j<=n;j++)
			id[j]=j;
		sort(id+1,id+n+1,[](int x,int y){
			return dep[x]<dep[y];
		});
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
			{
				int u=id[j],v=id[k];
				if (u==v)
					lca[u][v]=u;
				else if (u==fa[v])
					lca[u][v]=u;
				else if (v==fa[u])
					lca[u][v]=v;
				else if (dep[u]>dep[v])
					lca[u][v]=lca[fa[u]][v];
				else
					lca[u][v]=lca[u][fa[v]];
			}
		for (int j=1;j<=n;j++)
			for (int k=1;k<j;k++)
			{
				int l=lca[j][k];
				(ans+=dp[dep[j]-dep[l]][dep[k]-dep[l]])%=MOD;
			}
	}
	ans=(LL)ans*get_inv(n)%MOD;
	printf("%d\n",ans);
	return 0;
}