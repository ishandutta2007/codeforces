#include <stdio.h>

int check[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=b;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			check[d] = 1;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				for(int j=1;j<=a;j++)
				{
					if(j==i) continue;
					printf("%d %d\n",j,i);
				}
				goto u;
			}
		}
		u:;
	}
}