#include <stdio.h>
#define MOD 1000000007

long long int DP[100010][2];
int main()
{
	DP[1][0] = 1;
	DP[1][1] = 0;
	for(int i=2;i<=100000;i++)
	{
		DP[i][0] = (DP[i-1][0]+DP[i-1][1])%MOD;
		DP[i][1] = (DP[i-1][0])%MOD;
	}
	
	int a,b;
	scanf("%d%d",&a,&b);
	long long int s = DP[a][0]+DP[a][1];
	long long int t = DP[b][0]+DP[b][1];
	printf("%lld",(2*(s+t-1))%MOD);
}