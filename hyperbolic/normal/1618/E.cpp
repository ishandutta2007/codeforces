#include <stdio.h>

long long int x[40010],ans[40010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		
		long long int sum = 0;
		long long int b = (long long int)a*(a+1)/2;
		for(int i=1;i<=a;i++) sum += x[i];
		if(sum%b!=0)
		{
			printf("NO\n");
			continue;
		}
		
		long long int t = sum/b;
		x[a+1] = x[1];
		for(int i=1;i<=a;i++)
		{
			long long int s = (x[i]+t)-x[i+1];
			if(s<=0 || s%a!=0)
			{
				printf("NO\n");
				goto u;
			}
			ans[i+1] = s/a;
		}
		
		printf("YES\n");
		printf("%lld ",ans[a+1]);
		for(int i=2;i<=a;i++) printf("%lld ",ans[i]);
		printf("\n");
		
		u:;
	}
}