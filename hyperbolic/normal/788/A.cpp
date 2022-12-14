#include <stdio.h>

long long int abs(long long int k)
{
	return k>0?k:-k;
}

int x[100010];
long long int y[100010],DP[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++) y[i] = abs(x[i]-x[i+1]);
	for(int i=1;i<a;i++) DP[i] = -DP[i-1] + y[i];
	
	long long int min2 = 0, max2 = 0;
	long long int min1 = DP[1], max1 = DP[1];
	long long int ans = 0>abs(DP[1])?0:abs(DP[1]);
	for(int i=2;i<a;i++)
	{
		if(i%2==0)
		{
			long long int t1 = abs(DP[i] - min2);
			long long int t2 = abs(DP[i] + max1);
			ans = ans>t1?ans:t1;
			ans = ans>t2?ans:t2;
			min2 = min2<DP[i]?min2:DP[i];
			max2 = max2>DP[i]?max2:DP[i];
		}
		else
		{
			long long int t1 = abs(DP[i] - min1);
			long long int t2 = abs(DP[i] + max2);
			ans = ans>t1?ans:t1;
			ans = ans>t2?ans:t2;
			min1 = min1<DP[i]?min1:DP[i];
			max1 = max1>DP[i]?max1:DP[i];
		}
	}
	printf("%lld",ans);
}