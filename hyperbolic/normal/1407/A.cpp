#include <stdio.h>

int x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int count1 = 0, count0 = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++)
		{
			if(x[i]==1) count1++;
			else count0++;
		}
		
		if(count0>=a/2)
		{
			printf("%d\n",(a/2));
			for(int i=1;i<=(a/2);i++) printf("0 ");
			printf("\n");
		}
		else
		{
			int k = (a/2)+1;
			if(k%2==1)
			{
				printf("%d\n",k-1);
				for(int i=1;i<k;i++) printf("1 ");
				printf("\n");
			}
			else
			{
				printf("%d\n",k);
				for(int i=1;i<=k;i++) printf("1 ");
				printf("\n");
			}
		}
	}
}