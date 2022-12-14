#include <stdio.h>

char x[110];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	scanf("%s",x+1);
	
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(b*i+c*j==a)
			{
				int p = 1;
				printf("%d\n",i+j);
				for(int k=1;k<=i;k++)
				{
					for(int l=1;l<=b;l++) printf("%c",x[p++]);
					printf("\n");
				}
				for(int k=1;k<=j;k++)
				{
					for(int l=1;l<=c;l++) printf("%c",x[p++]);
					printf("\n");
				}
				return 0;
			}
		}
	}
	printf("-1");
}