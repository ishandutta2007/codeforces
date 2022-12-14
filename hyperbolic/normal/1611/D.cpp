#include <stdio.h>

int x[200010],prev[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			prev[i] = b;
		}
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			x[b] = i;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(x[prev[i]]>x[i])
			{
				printf("-1\n");
				goto u;
			}
		}
		for(int i=1;i<=a;i++) printf("%d ",x[i]-x[prev[i]]);
		printf("\n");
		u:;
	}
}