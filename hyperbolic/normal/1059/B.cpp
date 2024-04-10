#include <stdio.h>
#include <string.h>

int direX[10]={0,1,1,1,0,-1,-1,-1};
int direY[10]={1,1,0,-1,-1,-1,0,1};

int check[1010][1010];
char x[1010][1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	for(int i=2;i<=a-1;i++)
	{
		for(int j=2;j<=b-1;j++)
		{
			for(int k=0;k<8;k++)
			{
				if(x[i+direX[k]][j+direY[k]]=='.')
				{
					goto u;
				}
			}
			
			for(int k=0;k<8;k++) check[i+direX[k]][j+direY[k]] = 1;
			
			u:;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#'&&check[i][j]==0)
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
}