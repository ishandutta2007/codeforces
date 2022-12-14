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
			if(a==3) printf("-1\n");
			else
			{
				printf("%d %d ",a,a-1);
				for(int i=3;i<=a;i++) printf("%d ",i-2);
				printf("\n");
			}
		}
		else
		{
			for(int i=1;i<=a;i+=2) printf("%d %d ",i+1,i);
			printf("\n");
		}
	}
}