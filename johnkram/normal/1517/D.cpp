#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,i,j,x,y,a[505][505],b[505][505],ans[10][505][505];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(k&1)
	{
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)printf("-1%c",j==m?'\n':' ');
		return 0;
	}
	for(i=1;i<=n;i++)for(j=1;j<m;j++)scanf("%d",b[i]+j);
	for(i=1;i<n;i++)for(j=1;j<=m;j++)scanf("%d",a[i]+j);
	k>>=1;
	for(i=1;i<=k;i++)for(x=1;x<=n;x++)for(y=1;y<=m;y++)
	{
		ans[i][x][y]=1<<30;
		if(x>1)ans[i][x][y]=ans[i-1][x-1][y]+a[x-1][y];
		if(x<n)ans[i][x][y]=min(ans[i][x][y],ans[i-1][x+1][y]+a[x][y]);
		if(y>1)ans[i][x][y]=min(ans[i][x][y],ans[i-1][x][y-1]+b[x][y-1]);
		if(y<m)ans[i][x][y]=min(ans[i][x][y],ans[i-1][x][y+1]+b[x][y]);
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)printf("%d%c",ans[k][i][j]<<1,j==m?'\n':' ');
	return 0;
}