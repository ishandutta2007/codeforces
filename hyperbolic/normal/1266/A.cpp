#include <stdio.h>
#include <string.h>

char x[110];
int check[20];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		
		int s = 0;
		for(int j=0;j<=9;j++) check[j] = 0;
		for(int j=1;j<=b;j++) check[x[j]-'0']++;
		for(int j=1;j<=b;j++) s += x[j]-'0';
		
		if(check[0]==0) printf("cyan\n");
		else if(s%3!=0) printf("cyan\n");
		else
		{
			check[0]--;
			for(int j=0;j<=9;j+=2)
			{
				if(check[j]>=1)
				{
					printf("red\n");
					goto u;
				}
			}
			for(int j=1;j<=9;j++)
			{
				if(check[j]>=1)
				{
					printf("cyan\n");
					goto u;
				}
			}
			printf("red\n");
			u:;
		}
	}
}