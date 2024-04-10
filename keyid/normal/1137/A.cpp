#include <bits/stdc++.h>
using namespace std;

const int MAXN=1005;

int a[MAXN][MAXN],row[MAXN][MAXN][2],col[MAXN][MAXN][2],b[MAXN];

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			b[j]=a[i][j];
		sort(b+1,b+m+1);
		int c=unique(b+1,b+m+1)-b;
		for (int j=1;j<=m;j++)
		{
			col[i][j][0]=lower_bound(b+1,b+c,a[i][j])-b;
			col[i][j][1]=c-1-col[i][j][0];
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
			b[j]=a[j][i];
		sort(b+1,b+n+1);
		int c=unique(b+1,b+n+1)-b;
		for (int j=1;j<=n;j++)
		{
			row[j][i][0]=lower_bound(b+1,b+c,a[j][i])-b;
			row[j][i][1]=c-1-row[j][i][0];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			printf("%d ",max(col[i][j][0],row[i][j][0])+max(col[i][j][1],row[i][j][1]));
		puts("");
	}
	return 0;
}