#include <stdio.h>

int x[5010];
long long int y[5010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int ans = (long long int)4e18;
	for(int j=1;j<=a;j++)
	{
		long long int sum = 0;
		y[j] = 0;
		for(int i=j+1;i<=a;i++)
		{
			long long int t = y[i-1];
			long long int s = t/x[i] + 1;
			sum += s;
			y[i] = s*x[i];
		}
		for(int i=j-1;i>=1;i--)
		{
			long long int t = y[i+1];
			long long int s = t/x[i] + 1;
			sum += s;
			y[i] = s*x[i];
		}
		ans = ans<sum?ans:sum;
	}
	printf("%lld",ans);
}