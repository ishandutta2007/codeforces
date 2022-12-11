#include <bits/stdc++.h>
using namespace std;

const int MAXN=105,INF=0x3f3f3f3f;

int n,m,g[MAXN][MAXN],t[MAXN][MAXN];

int solve(int x)
{
	memcpy(g,t,sizeof(g));
	int y=g[1][1]-x;
	for (int j=1;j<=m;j++)
	{
		g[1][j]-=x;
		if (g[1][j]<0) return INF;
	}
	for (int j=1;j<=n;j++)
	{
		g[j][1]-=y;
		if (g[j][1]<0) return INF;
	}
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++)
			g[i][j]-=g[i][1]+g[1][j];
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++)
			if (g[i][j])
				return INF;
	int ret=x+y;
	for (int i=1;i<=m;i++)
		ret+=g[1][i];
	for (int i=1;i<=n;i++)
		ret+=g[i][1];
	return ret;
}

int main()
{
	//freopen("read.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&t[i][j]);
	int ans=INF,x;
	for (int i=0;i<=t[1][1];i++)
	{
		int ret=solve(i);
		if (ret<ans)
		{
			ans=ret;
			x=i;
		}
	}
	if (ans==INF)
		printf("-1");
	else
	{
		printf("%d\n",ans);
		int y=t[1][1]-x;
		for (int i=0;i<x;i++)
			printf("row 1\n");
		for (int i=0;i<y;i++)
			printf("col 1\n");
		for (int i=1;i<=m;i++)
			t[1][i]-=x;
		for (int i=1;i<=n;i++)
			t[i][1]-=y;
		for (int i=2;i<=m;i++)
			for (int j=0;j<t[1][i];j++)
				printf("col %d\n",i);
		for (int i=2;i<=n;i++)
			for (int j=0;j<t[i][1];j++)
				printf("row %d\n",i);
	}
	return 0;
}