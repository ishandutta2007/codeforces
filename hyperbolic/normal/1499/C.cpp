#include <stdio.h>

long long int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		
		long long int ans = x[1]*a + x[2]*a;
		long long int min1 = x[1];
		long long int min2 = x[2];
		long long int sum1 = x[1], sum2 = x[2];
		int C1 = 1,C2 = 1;
		
		for(int i=3;i<=a;i++)
		{
			if(i%2==1)
			{
				sum1 += x[i];
				C1++;
				min1 = min1<x[i]?min1:x[i];
			}
			else
			{
				sum2 += x[i];
				C2++;
				min2 = min2<x[i]?min2:x[i];
			}
			
			long long int t1 = sum1 + (a-C1)*min1;
			long long int t2 = sum2 + (a-C2)*min2;
			ans = ans<t1+t2?ans:t1+t2;
		}
		printf("%lld\n",ans);
	}
}