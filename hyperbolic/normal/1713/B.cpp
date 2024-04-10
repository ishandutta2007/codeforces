#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int p = 1;
		for(int i=2;i<=a;i++) if(x[p] < x[i]) p = i;
		
		for(int i=p-1;i>=2;i--)
		{
			if(x[i]<x[i-1])
			{
				printf("NO\n");
				goto u;
			}
		}
		for(int i=p+1;i<a;i++)
		{
			if(x[i]<x[i+1])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}