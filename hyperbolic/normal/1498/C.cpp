#include <stdio.h>
#define MOD 1000000007

long long int DP[1010][1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a;i++) DP[i][1] = 1;
		for(int j=2;j<=b;j++)
		{
			DP[0][j] = 1;
			for(int i=1;i<=a;i++)
			{
				DP[i][j] = DP[i-1][j] + DP[a-i][j-1];
				DP[i][j] %= MOD;
			}
		}
		printf("%lld\n",DP[a][b]);
	}
}