#include <stdio.h>

int ans[100010];

int getQuery(int k)
{
	printf("? %d\n",k);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) ans[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			if(ans[i]==0)
			{
				int p = i;
				int p2 = getQuery(p);
				while(ans[p2]==0)
				{
					int t = getQuery(p);
					ans[p2] = t;
					p2 = t;
				}
			}
		}
		
		printf("! ");
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
		fflush(stdout);
	}
}