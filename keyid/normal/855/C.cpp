#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back

const int MAXN=100005,MOD=1000000007;

int M,K,x,f[MAXN][11][3],tmp[11][3];
vector <int> G[MAXN];

void dfs(int u,int fa)
{
	f[u][1][0]=1;
	f[u][0][1]=1;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (v!=fa)
		{
			dfs(v,u);
			memcpy(tmp,f[u],sizeof(tmp));
			memset(f[u],0,sizeof(f[u]));
			for (int k=0;k<=x;k++)
				for (int j=0;j<=k;j++)
				{
					f[u][k][0]=(f[u][k][0]+(LL)tmp[k-j][0]*(K-1)%MOD*(f[v][j][1]+f[v][j][2]))%MOD;
					f[u][k][1]=(f[u][k][1]+((LL)(M-1)*f[v][j][1]+(LL)(K-1)*f[v][j][2])%MOD*tmp[k-j][1])%MOD;
					f[u][k][2]=(f[u][k][2]+(f[v][j][0]+(LL)(M-1)*f[v][j][1]+(LL)(K-1)*f[v][j][2])%MOD*tmp[k-j][2]+(LL)tmp[k-j][1]*f[v][j][0])%MOD;
				}
		}
	}
	// for (int i=0;i<=x;i++)
	// {
	// 	f[u][i][2]=(LL)(K-1)*(f[u][i][1]+f[u][i][2])%MOD;
	// 	f[u][i][1]=(LL)(M-1)*f[u][i][1]%MOD;
	// }
}

int main()
{
	int n;
	scanf("%d%d",&n,&M);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	scanf("%d%d",&K,&x);
	dfs(1,0);
	int ans=0;
	for (int i=0;i<=x;i++)
	{
		ans=(ans+f[1][i][0]+(LL)(M-1)*f[1][i][1]+(LL)(K-1)*f[1][i][2])%MOD;
	}
	// for (int i=0;i<=x;i++)
	// {
	// 	for (int j=0;j<3;j++)
	// 	{
	// 		printf("%d ",f[1][i][j]);
	// 	}
	// 	puts("");
	// }
	printf("%d",ans);
	return 0;
}