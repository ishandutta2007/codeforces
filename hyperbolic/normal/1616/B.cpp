#include <stdio.h>

char x[100010];
int check[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		scanf("%s",x+1);
		if(a==1)
		{
			printf("%c%c\n",x[1],x[1]);
			continue;
		}
		if(x[1]==x[2])
		{
			printf("%c%c\n",x[1],x[1]);
			continue;
		}
		
		for(int i=1;i<a;i++) if(x[i]<x[i+1]) check[i] = 1;
		
		for(int i=1;i<=a;i++)
		{
			if(check[i]==1)
			{
				
				for(int j=1;j<=i;j++) printf("%c",x[j]);
				for(int j=i;j>=1;j--) printf("%c",x[j]);
				printf("\n");
				goto u;
			}
		}
		
		for(int j=1;j<=a;j++) printf("%c",x[j]);
		for(int j=a;j>=1;j--) printf("%c",x[j]);
		printf("\n");
		u:;
	}
}