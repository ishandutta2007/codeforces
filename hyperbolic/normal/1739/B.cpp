#include <stdio.h>

int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		y[1] = x[1];
		for(int i=2;i<=a;i++) y[i] = y[i-1]+x[i];
		for(int i=2;i<=a;i++)
		{
			if(y[i-1]-x[i]>=0 && y[i-1]-x[i] != y[i])
			{
				printf("-1\n");
				goto u;
			}
		}
		for(int i=1;i<=a;i++) printf("%d ",y[i]);
		printf("\n");
		u:;
	}
}