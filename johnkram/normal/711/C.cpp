#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
ll f[105][105][105],g[105][105][105],h[105][105][105];
int n,m,K,a[105],b[105][105],i,j,k;
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",b[i]+j);
	memset(h,63,sizeof(h));
	memset(g,63,sizeof(g));
	memset(f,63,sizeof(f));
	f[0][0][0]=0;
	for(i=0;i<=m;i++)g[0][0][i]=0;
	for(i=1;i<=n;i++)for(j=1;j<=K;j++)
	{
		if(a[i])f[i][j][a[i]]=min(g[i-1][j-1][a[i]-1],min(h[i-1][j-1][a[i]+1],f[i-1][j][a[i]]));
		else for(k=1;k<=m;k++)f[i][j][k]=min(g[i-1][j-1][k-1],min(h[i-1][j-1][k+1],f[i-1][j][k]))+b[i][k];
		for(k=1;k<=m;k++)g[i][j][k]=min(g[i][j][k-1],f[i][j][k]);
		for(k=m;k;k--)h[i][j][k]=min(h[i][j][k+1],f[i][j][k]);
	}
	if(g[n][K][m]==f[0][0][1])g[n][K][m]=-1;
	cout<<g[n][K][m]<<endl;
	return 0;
}