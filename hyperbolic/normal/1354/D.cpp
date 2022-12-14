#include <stdio.h>

int check[2100010];


int C = 1048575;
void func1(int k, int type)
{
	k+=C;
	while(k)
	{
		if(type==1) check[k]++;
		else check[k]--;
		k/=2;
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		func1(c,1);
	}
	
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		if(c>0) func1(c,1);
		else
		{
			c*=-1;
			int S = 0;
			int p = 1;
			while(p<=C)
			{
				if(check[2*p]<c-S)
				{
					S += check[2*p];
					p = 2*p+1;
				}
				else p = 2*p;
			}
			func1(p-C,-1);
		}
	}
	
	if(check[1]==0)
	{
		printf("0");
		return 0;
	}
	
	int p = 1;
	while(p<=C)
	{
		if(check[2*p]>0) p = 2*p;
		else p = 2*p+1;
	}
	printf("%d",p-C);
}