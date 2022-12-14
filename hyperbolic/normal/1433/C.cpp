#include <stdio.h>
#include <algorithm>

int x[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int max = x[1];
		for(int i=2;i<=a;i++) max = max>x[i]?max:x[i];
		for(int i=1;i<=a;i++)
		{
			if(x[i]==max)
			{
				if(i-1>=1 && x[i-1]<x[i])
				{
					printf("%d\n",i);
					goto u;
				}
				if(i+1<=a&&x[i+1]<x[i])
				{
					printf("%d\n",i);
					goto u;
				}
			}
		}
		printf("-1\n");
		u:;
	}
}