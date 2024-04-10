#include <stdio.h>
#include <string.h>
#define MOD 998244353

int value[3][1010];
long long int DP[3][1010][1010];
char x[1010], y[1010];
int main()
{
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	int b = strlen(y+1);
	
	for(int i=1;i<=a;i++)
	{
		value[1][i] = 1;
		for(int j=i+1;j<=a;j++)
		{
			if(x[j]!=x[j-1]) value[1][i]++;
			else break;
		}
	}
	for(int i=1;i<=b;i++)
	{
		value[2][i] = 1;
		for(int j=i+1;j<=b;j++)
		{
			if(y[j]!=y[j-1]) value[2][i]++;
			else break;
		}
	}
	
	for(int i=a;i>=1;i--)
	{
		for(int j=b;j>=1;j--)
		{
			DP[1][i][j] = 0;
			if(x[i]!=x[i+1]) DP[1][i][j] += DP[1][i+1][j];
			if(x[i]!=y[j]) DP[1][i][j] += DP[2][i+1][j];
			if(x[i]!=y[j]) DP[1][i][j] += value[2][j];
			DP[1][i][j] %= MOD;
			
			DP[2][i][j] = 0;
			if(y[j]!=y[j+1]) DP[2][i][j] += DP[2][i][j+1];
			if(y[j]!=x[i]) DP[2][i][j] += DP[1][i][j+1];
			if(y[j]!=x[i]) DP[2][i][j] += value[1][i];
			DP[2][i][j] %= MOD;
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=1;k<=2;k++) ans += DP[k][i][j], ans %= MOD;
		}
	}
	
	printf("%lld",ans);
}