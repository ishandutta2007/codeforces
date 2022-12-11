#include <bits/stdc++.h>
using namespace std;

const int MAXN=5005,INF=0x3f3f3f3f;

int n,b,c[MAXN],d[MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
vector <int> G[MAXN];

int dfs(int u)
{
	int su=0;
	f[u][0]=g[u][0]=0;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		int sv=dfs(v);
		su+=sv;
		for (int j=su;j>=1;j--)
			for (int k=max(1,j-(su-sv));k<=sv&&k<=j;k++)
			{
				f[u][j]=min(f[u][j],f[u][j-k]+f[v][k]);
				g[u][j]=min(g[u][j],g[u][j-k]+g[v][k]);
			}
	}
	su++;
	int t=c[u]-d[u];
	for (int i=su;i>=1;i--)
	{
		g[u][i]=min(g[u][i],g[u][i-1]+c[u]);
		f[u][i]=min(f[u][i-1]+t,g[u][i]);
	}
	return su;
}

int main()
{
	//freopen("read.txt","r",stdin);
	scanf("%d%d",&n,&b);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
		if (i>1)
		{
			int x;
			scanf("%d",&x);
			G[x].push_back(i);
		}
	}
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	dfs(1);
	// for (int i=0;i<=n;i++)
	// 	printf("%d\n",f[1][i]);
	for (int i=n;i>=0;i--)
		if (f[1][i]<=b)
		{
			printf("%d\n",i);
			break;
		}
	return 0;
}