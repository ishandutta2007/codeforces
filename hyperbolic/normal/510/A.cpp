#include <stdio.h>

int main()
{
	int a,b,i,j;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			if(i%2==1)
			{
				printf("#");
			}
			else if(i%4==2)
			{
				if(j==b) printf("#");
				else printf(".");
			}
			else
			{
				if(j==1) printf("#");
				else printf(".");
			}
		}
		printf("\n");
	}
}