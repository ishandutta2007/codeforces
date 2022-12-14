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
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[x[i]] = i;
		
		int R = a;
		int p = 1;
		while(p<=a)
		{
			int start = y[p];
			for(int i=start;i<=R;i++)
			{
				if(x[i] != i-start+p)
				{
					printf("No\n");
					goto u;
				}
			}
			p = R-start+p+1;
			R = start-1;
		}
		printf("Yes\n");
		u:;
	}
}