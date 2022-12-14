#include <stdio.h>

int x[510][510];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(i==1&&x[i][j]>=4)
				{
					printf("NO\n");
					goto u;
				}
				else if(i==a&&x[i][j]>=4)
				{
					printf("NO\n");
					goto u;
				}
				else if(j==1&&x[i][j]>=4)
				{
					printf("NO\n");
					goto u;
				}
				else if(j==b&&x[i][j]>=4)
				{
					printf("NO\n");
					goto u;
				}
				if(x[i][j]>=5)
				{
					printf("NO\n");
					goto u;
				}
			}
		}
		if(x[1][1]>=3)
		{
			printf("NO\n");
			goto u;
		}
		if(x[1][b]>=3)
		{
			printf("NO\n");
			goto u;
		}
		if(x[a][1]>=3)
		{
			printf("NO\n");
			goto u;
		}
		if(x[a][b]>=3)
		{
			printf("NO\n");
			goto u;
		}
		
		printf("YES\n");
		printf("2 ");
		for(int j=2;j<=b-1;j++) printf("3 ");
		printf("2\n");
		
		for(int i=2;i<=a-1;i++)
		{
			printf("3 ");
			for(int j=2;j<=b-1;j++) printf("4 ");
			printf("3\n");
		}
		
		printf("2 ");
		for(int j=2;j<=b-1;j++) printf("3 ");
		printf("2\n");
		u:;
	}
}