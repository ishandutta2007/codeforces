#include <stdio.h>

int x[100010],ans[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		x[a+1] = x[a]+1;
		
		int start = 1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]<x[i+1])
			{
				ans[i] = start;
				start = i+1;
			}
			else ans[i] = i+1;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(ans[i]==i)
			{
				printf("-1\n");
				goto u;
			}
		}
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
		u:;
	}
}