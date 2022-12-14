#include <stdio.h>
#include <algorithm>

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
		std::sort(x+1,x+a+1);
		
		long long int sum1 = 0, sum2 = 0;
		for(int i=1;i<=a;i++) sum1 +=x[i];
		double ans = -2234567890;
		for(int i=a;i>=2;i--)
		{
			sum1 -= x[i];
			sum2 += x[i];
			double t = (double)sum1/(i-1) + (double)sum2/(a-i+1);
			ans = ans>t?ans:t;
		}
		printf("%.12lf\n",ans);
	}
}