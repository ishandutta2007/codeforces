#include <stdio.h>

long long int x[300010];
long long int DP[300010][3],DP2[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	DP[1][0] = x[1];
	DP[1][1] = b*x[1];
	for(int i=2;i<=a;i++)
	{
		DP[i][0] = DP[i-1][0]+x[i]>x[i]?DP[i-1][0]+x[i]:x[i];
		DP[i][1] = DP[i-1][1]+b*x[i];
		DP[i][1] = DP[i][1] > b*x[i]? DP[i][1]: b*x[i];
		DP[i][1] = DP[i][1] > DP[i-1][0] + b*x[i]? DP[i][1] : DP[i-1][0]+b*x[i];
	}
	for(int i=a;i>=1;i--) DP2[i] = DP2[i+1]+x[i]>x[i]?DP2[i+1]+x[i]:x[i];
	long long int ans = 0;
	for(int i=0;i<=a;i++) for(int j=0;j<=1;j++) ans = ans>DP[i][j]+DP2[i+1]?ans:DP[i][j]+DP2[i+1];
	for(int i=0;i<=a;i++) for(int j=0;j<=1;j++) ans = ans>DP[i][j]?ans:DP[i][j];
	printf("%lld",ans);
}