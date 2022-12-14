#include <stdio.h>

int check[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	int p = 1;
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		c%=(a-i+1);
		for(int j=1;j<=c;j++)
		{
			p++;
			if(p>a) p = 1;
			while(check[p]==1)
			{
				p++;
				if(p>a) p = 1;
			}
		}
		printf("%d ",p);
		check[p] = 1;
		p++;
		if(p>a) p = 1;
		while(check[p]==1)
		{
			p++;
			if(p>a) p = 1;
		}
	}
}