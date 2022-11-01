#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,i,j,k;
int l[4005],d[4005],c[4005],dp[4005][1<<11],f[4005][1<<11],g[4005],ans;

int s(int vl,int msk)
{
	int ans=c[vl];
	while(msk&1)
	{
		vl++;
		ans+=c[vl];
		msk>>=1;
	}
	return ans;
}

int main()
{
	memset(dp,-0x3f,sizeof(dp));
	memset(f,-0x3f,sizeof(f));
	memset(g,-0x3f,sizeof(g));
	g[1]=0;
	
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",&l[i]);
	rep(i,n) scanf("%d",&d[i]);
	rep(i,n+m) scanf("%d",&c[i]);
	
	per(i,n)
	{
		for (j=l[i];j;j--)
		{
			dp[i][1]=max(dp[i][1],g[j]-d[i]+c[l[i]]);
		}
		for (j=0;j<(1<<11);j++)
		{
			dp[i][j+1]=max(dp[i][j+1],f[l[i]][j]-d[i]+s(l[i],j));
		}
		
		for (j=0;j<(1<<11);j++)
		{
			ans=max(ans,dp[i][j]);
			int t=j;
			for (k=l[i];k<=n+m&&t;k++)
			{
				f[k][t]=max(f[k][t],dp[i][j]);
				t>>=1;
			}
			if (k<=n+m) g[k]=max(g[k],dp[i][j]);
		}
	}
	
	printf("%d\n",ans);
	return 0;
}