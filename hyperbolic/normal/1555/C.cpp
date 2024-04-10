#include <stdio.h>

int x[100010],y[100010],sum1[100010],sum2[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int i=1;i<=a;i++) sum1[i] = sum1[i-1] + x[i];
		for(int i=1;i<=a;i++) sum2[i] = sum2[i-1] + y[i];
		
		int ans = 1234567890;
		for(int i=1;i<=a;i++)
		{
			int s1 = sum1[a] - sum1[i];
			int s2 = sum2[i-1];
			int M = s1>s2?s1:s2;
			ans = ans<M?ans:M;
		}
		printf("%d\n",ans);
	}
}