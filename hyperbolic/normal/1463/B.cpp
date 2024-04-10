#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int sum1 = 0 ,sum2 = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i+=2) sum1 += x[i];
		for(int i=2;i<=a;i+=2) sum2 += x[i];
		if(sum1<=sum2)
		{
			for(int i=1;i<=a;i++)
			{
				if(i%2==1) printf("1 ");
				else printf("%d ",x[i]);
			}
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				if(i%2==0) printf("1 ");
				else printf("%d ",x[i]);
			}
			printf("\n");
		}
	}
}