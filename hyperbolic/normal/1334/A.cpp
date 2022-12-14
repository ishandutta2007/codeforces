#include <stdio.h>

int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<a;i++)
		{
			if(x[i]>x[i+1])
			{
				printf("NO\n");
				goto u;
			}
			if(y[i]>y[i+1])
			{
				printf("NO\n");
				goto u;
			}
		}
		for(int i=1;i<=a;i++)
		{
			if((x[i]-x[i-1])<(y[i]-y[i-1]))
			{
				printf("NO\n");
				goto u;
			}
		}
		
		printf("YES\n");
		u:;
	}
}