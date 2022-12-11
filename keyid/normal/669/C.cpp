#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;

struct Point
{
	int x,y;
}a[MAXN][MAXN];

int ans[MAXN][MAXN];

int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=(Point){i,j};
	for (int t,r,c,x;q--;)
	{
		scanf("%d",&t);
		if (t==1)
		{
			scanf("%d",&r);
			for (int i=1;i<m;i++) swap(a[r][i],a[r][i+1]);
		}
		else if (t==2)
		{
			scanf("%d",&c);
			for (int i=1;i<n;i++) swap(a[i][c],a[i+1][c]);
		}
		else
		{
			scanf("%d%d%d",&r,&c,&x);
			ans[a[r][c].x][a[r][c].y]=x;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}