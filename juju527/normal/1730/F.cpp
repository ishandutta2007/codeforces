#include<cstdio>
#include<algorithm>
int n,k,f[5005],g[5005];
int dp[5005][550],w[5005][5005];
int main()
{
	scanf("%d%d",&n,&k);++k;
	for (int i=1;i<=n;i++) scanf("%d",&f[i]),g[f[i]]=i;
	int all=(1<<k)-1;
	for (int i=0;i<=n;i++) for (int sta=0;sta<(1<<k);sta++) dp[i][sta]=1000000000;
	for (int i=1;i<=n;i++) for (int x=1;x<=n;x++) w[i][x]=w[i][x-1]+(g[x]>g[i]);
	dp[0][all]=0;
	for (int i=0;i<=n;i++)
		for (int sta=0;sta<(1<<k);sta++)
		{
			if (dp[i][sta]>500000000) continue;
			if (i!=n&&(sta&(1<<(k-1)))&&i<n) dp[i+1][(sta*2)&all]=std::min(dp[i+1][(sta*2)&all],dp[i][sta]);
			for (int x=0;x<k;x++)
			{
				if (i-x<=0||(sta&(1<<x))) continue;
				int nsta=sta|(1<<x),pos=g[i-x],w1=0;
				for (int d=0;d<k;d++) if (i-d>=0&&(sta&(1<<d))) if (g[i-d]>pos) ++w1;
				dp[i][nsta]=std::min(dp[i][nsta],dp[i][sta]+(i-k>=0?w[i-x][i-k]:0)+w1);
			}
		}
	printf("%d\n",dp[n][all]);
	return 0;
}