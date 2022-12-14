#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int count0 = 0, count1 = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b==0) count0++;
			if(b==1) count1++;
		}
		
		long long int ans = 1;
		for(int i=1;i<=count0;i++) ans*=2;
		ans *= count1;
		printf("%lld\n",ans);
	}
}