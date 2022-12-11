#include <cstdio>
#include <cstring>

const int MOD=1000000007,MAX=100010;

char s[MAX],t[MAX];
int f[MAX],dp[MAX],sum[MAX];

void getfail()
{
	int m=strlen(t);
	for (int i=1;i<m;i++)
	{
		int j=f[i];
		while (j&&t[i]!=t[j]) j=f[j];
		f[i+1]= t[i]==t[j]?j+1:0;
	}
}

int kmp()
{
	int n=strlen(s),m=strlen(t);
	int j=0,left=-1;
	sum[0]=1;
	for (int i=0;i<n;i++)
	{
		while (j&&t[j]!=s[i]) j=f[j];
		if (t[j]==s[i]) j++;
		if (j==m) left=i+1-m;
		dp[i+1]=(dp[i]+(left>=0?sum[left]:0))%MOD;
		sum[i+1]=(sum[i]+dp[i+1]+1)%MOD;
	}
	return dp[n];
}

int main()
{
	scanf("%s%s",s,t);
	getfail();
	printf("%d",kmp());
	return 0;
}