#include <stdio.h>

int check[200010],ans[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		printf("2\n");
		int s = 1;
		for(int i=1;i<=a;i+=2)
		{
			if(check[i]==0)
			{
				int k = i;
				while(k<=a)
				{
					check[k] = 1;
					ans[s++] = k;
					k*=2;
				}
			}
		}
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}