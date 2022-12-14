#include <stdio.h>

int x[100010];
long long int DP[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	x[0] = 0, x[a+1] = b;
	
	DP[a+1] = 0;
	DP[a] = b-x[a];
	for(int i=a-1;i>=0;i--) DP[i] = DP[i+2] + (x[i+1]-x[i]);
	
	long long int ans = DP[0];
	long long int sum = 0;
	for(int i=1;i<=a+1;i++)
	{
		if(x[i-1]+1==x[i])
		{
			if(i%2==1) sum += (x[i]-x[i-1]);
			continue;
		}
		
		if(i%2==1)
		{
			long long int s = x[i]-1 - x[i-1] + DP[i] + sum;
			ans = ans>s?ans:s;
			sum += (x[i]-x[i-1]);
		}
		else
		{
			long long int s = DP[i-1] - 1 + sum;
			ans = ans>s?ans:s;
		}
	}
	printf("%lld",ans);
}