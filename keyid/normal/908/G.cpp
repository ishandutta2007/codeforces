#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=705,MOD=1000000007;

char s[MAXN];
int dp[MAXN][10][MAXN],dp2[MAXN][10][MAXN],pw[MAXN];

int main()
{
	scanf("%s",s);
	int n=strlen(s);
	pw[0]=1;
	for (int i=1;i<n;i++)
		pw[i]=pw[i-1]*10LL%MOD;
	for (int k=1;k<10;k++)
		dp2[0][k][0]=1;
	for (int i=1;i<n;i++)
		for (int k=1;k<10;k++)
			for (int j=0;j<=i;j++)
			{
				dp[i][k][j]=(LL)dp[i-1][k][j]*k%MOD;
				dp2[i][k][j]=(LL)dp2[i-1][k][j]*k%MOD;
				if (j)
				{
					dp[i][k][j]=(dp[i][k][j]+dp[i-1][k][j-1]*10LL*(9-k))%MOD;
					dp2[i][k][j]=(dp2[i][k][j]+dp2[i-1][k][j-1]*(9LL-k))%MOD;
				}
				if (j<i)
				{
					dp[i][k][j]=(dp[i][k][j]+dp[i-1][k][j]*10LL+(LL)k*pw[j]%MOD*dp2[i-1][k][j])%MOD;
					dp2[i][k][j]=(dp2[i][k][j]+dp2[i-1][k][j])%MOD;
				}
			}
	int cnt[10],ans=0;
	memset(cnt,0,sizeof(cnt));
	for (int i=0;i<n;i++)
	{
		int c=s[i]-'0';
		for (int j=0;j<c;j++)
		{
			cnt[j]++;
			int now=0;
			for (int k=9;k>=1;k--)
			{
				int l=n-1-i,d=0;
				for (int m=0;m<cnt[k];m++)
					d=(d*10LL+k)%MOD;
				for (int m=0;m<=l;m++)
					ans=(ans+(LL)dp[l][k][m]*pw[now+cnt[k]]+(LL)dp2[l][k][m]*pw[now+m]%MOD*d)%MOD;
				now+=cnt[k];
			}
			cnt[j]--;
		}
		cnt[c]++;
	}
	int d=0;
	sort(s,s+n);
	for (int i=0;i<n;i++)
		d=(d*10LL+s[i]-'0')%MOD;
	ans=(ans+d)%MOD;
	printf("%d",ans);
	return 0;
}