#include <bits/stdc++.h>
using namespace std;

const int MAXN=1005;

int x1,y1,x2,y2,a[MAXN][MAXN],st[10][10][MAXN][MAXN];

bool check(int x)
{
	int tx1=x1+x-1,ty1=y1+x-1;
	int k1=31-__builtin_clz(x2-tx1+1),k2=31-__builtin_clz(y2-ty1+1);
	return max(max(st[k1][k2][tx1+(1<<k1)-1][ty1+(1<<k2)-1],st[k1][k2][tx1+(1<<k1)-1][y2]),max(st[k1][k2][x2][ty1+(1<<k2)-1],st[k1][k2][x2][y2]))>=x;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j])
			{
				int k=min(st[0][0][i-1][j],st[0][0][i][j-1]);
				st[0][0][i][j]=k;
				if (a[i-k][j-k]) st[0][0][i][j]++;
			}
	for (int i=1;(1<<i)<=n;i++)
		for (int j=(1<<i);j<=n;j++)
			for (int k=1;k<=m;k++)
				st[i][0][j][k]=max(st[i-1][0][j-(1<<i-1)][k],st[i-1][0][j][k]);
	for (int i=0;(1<<i)<=n;i++)
		for (int j=1;(1<<j)<=m;j++)
			for (int k=(1<<i);k<=n;k++)
				for (int l=(1<<j);l<=m;l++)
					st[i][j][k][l]=max(st[i][j-1][k][l-(1<<j-1)],st[i][j-1][k][l]);
	int Q;
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int l=1,r=min(x2-x1,y2-y1)+1;
		while (l<=r)
		{
			int m=l+r>>1;
			if (check(m)) l=m+1;
			else r=m-1;
		}
		printf("%d\n",r);
	}
	return 0;
}