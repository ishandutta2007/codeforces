#include <stdio.h>

int check[1010][1010];
int x[5][5];
int main()
{
	x[0][0] = 1, x[0][1] = 1, x[1][0] = 1, x[1][1] = 1, x[1][2] = 1, x[2][1] = 1, x[2][2] = 1;
	int a;
	scanf("%d",&a);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<=2;j++)
		{
			for(int k=0;k<=2;k++)
			{
				if(x[j][k]==1) check[i+j][i+k] = 1;
			}
		}
	}
	
	int count = 0;
	for(int i=1;i<=a+2;i++)
	{
		for(int j=1;j<=a+2;j++)
		{
			if(check[i][j]==1) count++;
		}
	}
	printf("%d\n",count);
	for(int i=1;i<=a+2;i++)
	{
		for(int j=1;j<=a+2;j++)
		{
			if(check[i][j]==1) printf("%d %d\n",i,j);
		}
	}
}