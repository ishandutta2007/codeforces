#include <stdio.h>
#include <string.h>

char x[510],y[1010];
int check[510][1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",x+1,y+1);
		int a = strlen(x+1);
		int b = strlen(y+1);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) check[i][j] = 0;
		x[a+1] = y[b+1] = 0;
		
		for(int i=0;i<=a;i++) check[i][b+1] = 1;
		for(int j=b;j>=1;j--)
		{
			for(int i=1;i<=a;i++)
			{
				if(x[i]==y[j] && check[i-1][j+1]==1) check[i][j] = 1;
				else check[i][j] = 0;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]==y[1])
			{
				if(check[i-1][2]==1)
				{
					printf("YES\n");
					goto u;
				}
				for(int j=1;j<=b&&i+j-1<=a;j++)
				{
					if(check[i+j-1-1][j+1]==1)
					{
						printf("YES\n");
						goto u;
					}
					if(x[i+j]!=y[j+1])
					{
						break;
					}
				}
			}
		}
		printf("NO\n");
		u:;
	}
}