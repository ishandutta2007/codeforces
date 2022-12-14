#include <stdio.h>

long long int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=a-b+1;i<=a;i++) scanf("%lld",&x[i]);
		if(b==1)
		{
			printf("Yes\n");
			continue;
		}
		
		long long int val = x[a-b+2]-x[a-b+1];
		for(int i=a-b+1;i+2<=a;i++)
		{
			if(x[i+1]-x[i]>x[i+2]-x[i+1])
			{
				printf("No\n");
				goto u;
			}
		}
		
		for(int i=a-b;i>=1;i--) x[i] = x[i+1] - val;
		if(x[1]<=val) printf("Yes\n");
		else printf("No\n");
		u:;
	}
}