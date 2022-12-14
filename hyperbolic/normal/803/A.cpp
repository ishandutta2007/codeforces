#include <stdio.h>

int ans[110][110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b>a*a)
	{
		printf("-1");
		return 0;
	}
	
	int count = b;
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
		{
			if(j==i)
			{
				if(count>=1)
				{
					count--;
					ans[i][j] = 1;
				}
			}
			else
			{
				if(count>=2)
				{
					count-=2;
					ans[i][j] = ans[j][i] = 1;
				}
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}