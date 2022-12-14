#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%2==1)
		{
			for(int i=1;i<=a;i++)
			{
				for(int j=i+1;j<=a;j++)
				{
					if((i+j)%2==1) printf("1 ");
					else printf("-1 ");
				}
			}
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				for(int j=i+1;j<=a;j++)
				{
					if(i%2==1 && j==i+1) printf("0 ");
					else if((i+j)%2==1) printf("1 ");
					else printf("-1 ");
				}
			}
			printf("\n");
		}
	}
}