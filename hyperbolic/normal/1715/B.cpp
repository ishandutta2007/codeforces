#include <stdio.h>

long long int ans[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		long long int d;
		scanf("%d%d%d%lld",&a,&b,&c,&d);
		if((long long int)b*c>d)
		{
			printf("-1\n");
			continue;
		}
		
		for(int i=1;i<=a;i++) ans[i] = 0;
		ans[1] = (long long int)b*c;
		long long int s = d - ans[1];
		for(int i=a;i>=1;i--)
		{
			long long int val = s<b-1?s:b-1;
			ans[i] += val;
			s -= val;
		}
		if(s>0) printf("-1\n");
		else
		{
			for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
			printf("\n");
		}
	}
}