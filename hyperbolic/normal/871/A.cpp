#include <stdio.h>
#define MAX 1000000000
int check[100010];
int prime[40010],p=1;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b%4==3)
		{
			if(b>=15) printf("%d\n",(b-15)/4+2);
			else printf("-1\n");
		}
		else if(b%4==2)
		{
			if(b>=6) printf("%d\n",(b-6)/4+1);
			else printf("-1\n");
		}
		else if(b%4==1)
		{
			if(b>=9) printf("%d\n",(b-9)/4+1);
			else printf("-1\n");
		}
		else printf("%d\n",b/4);
	}
}