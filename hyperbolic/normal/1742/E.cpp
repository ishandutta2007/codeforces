#include <stdio.h>

long long int x[200010],sum[200010],max[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=a;i++) sum[i] = x[i], max[i] = x[i];
		for(int i=1;i<=a;i++) sum[i] += sum[i-1], max[i] = max[i]>max[i-1]?max[i]:max[i-1];
		
		while(b--)
		{
			int c;
			scanf("%d",&c);
			
			long long int ans = 0;
			int min = 1, M = a;
			while(min<=M)
			{
				int h = (min+M)/2;
				if(max[h]<=c)
				{
					ans = sum[h];
					min = h+1;
				}
				else M = h-1;
			}
			printf("%lld ",ans);
		}
		printf("\n");
	}
}