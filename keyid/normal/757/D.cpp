#include <bits/stdc++.h>
using namespace std;

const int MAXN=80,MOD=1000000007;

char a[MAXN];
int pre[MAXN],dp[MAXN][1<<20];

int main()
{
	int n;
	scanf("%d%s",&n,a+1);
	for (int lst=0,i=1;i<=n;i++)
	{
		pre[i]=lst;
		if (a[i]=='1') lst=i;
	}
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		int now=0;
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		dp[i][0]++;
		for (int j=i;j>=1;j=pre[j])
		{
			if (i-j>4) break;
			if (a[j]=='1') now|=1<<i-j;
			if (!now) continue;
			if (now>20) break;
			if (pre[j])
				for (int u=0;u<(1<<20);u++)
					(dp[i][u|(1<<now-1)]+=(dp[j-1][u]-dp[pre[j]-1][u]+MOD)%MOD)%=MOD;
			else
				for (int u=0;u<(1<<20);u++)
					(dp[i][u|(1<<now-1)]+=dp[j-1][u])%=MOD;
		}
	}
	int ans=0;
		for (int j=1;j<=20;j++)
			(ans+=dp[n][(1<<j)-1])%=MOD;
	printf("%d",ans);
	return 0;
}