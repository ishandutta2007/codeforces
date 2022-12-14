#include <stdio.h>

int prime[20]={0,2,3,5,7,11,13,17,19,23,29,31};
int color[1010],check[20],ans[20];
int x[1010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) color[i] = 0;
		for(int i=1;i<=11;i++) check[i] = ans[i] = 0;
		
		int s = 1;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=11;j++)
			{
				if(x[i]%prime[j]==0)
				{
					color[i] = j;
					if(check[j]==0)
					{
						check[j] = 1;
						ans[j] = s++;
					}
					break;
				}
			}
		}
		printf("%d\n",s-1);
		for(int i=1;i<=a;i++) printf("%d ",ans[color[i]]);
		printf("\n");
	}
}