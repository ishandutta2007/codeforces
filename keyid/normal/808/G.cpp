#include <bits/stdc++.h>
using namespace std;

const int MAXL=100005,SIGMA=26,INF=0x3f3f3f3f;

char s[MAXL],t[MAXL];
int f[MAXL],g[MAXL][SIGMA],dp[2][MAXL];

void get_fail(int m)
{
	for (int i=1;i<m;i++)
	{
		int j=f[i];
		while (j&&t[i]!=t[j])
			j=f[j];
		f[i+1]=(t[i]==t[j]?j+1:0);
	}
	g[0][t[0]-'a']=1;
	for (int i=1;i<=m;i++)
		for (int j=0;j<SIGMA;j++)
			if (t[i]-'a'!=j)
				g[i][j]=g[f[i]][j];
			else
				g[i][j]=i+1;
}

int main()
{
	scanf("%s%s",s,t);
	int ls=strlen(s),lt=strlen(t);
	get_fail(lt);
	int last=0,now=1;
	for (int i=1;i<=lt;i++)
		dp[0][i]=-INF;
	for (int i=0;i<ls;i++)
	{
		for (int j=0;j<=lt;j++)
			dp[now][j]=-INF;
		if (s[i]=='?')
		{
			for (int j=0;j<=lt;j++)
				for (int k=0;k<SIGMA;k++)
					dp[now][g[j][k]]=max(dp[now][g[j][k]],dp[last][j]);
		}
		else
		{
			for (int j=0;j<=lt;j++)
				dp[now][g[j][s[i]-'a']]=max(dp[now][g[j][s[i]-'a']],dp[last][j]);
		}
		dp[now][lt]++;
		swap(last,now);
	}
	int ans=0;
	for (int i=0;i<=lt;i++)
		ans=max(ans,dp[last][i]);
	printf("%d",ans);
	return 0;
}