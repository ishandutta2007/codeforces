#include <stdio.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=8;i++) scanf("%s",x[i]+1);
		
		for(int i=2;i<=7;i++)
		{
			for(int j=2;j<=7;j++)
			{
				if(x[i][j]=='#'&&x[i-1][j-1]=='#'&&x[i-1][j+1]=='#'&&x[i+1][j-1]=='#'&&x[i+1][j+1]=='#')
				{
					printf("%d %d\n",i,j);
					goto u;
				}
			}
		}
		u:;
	}
}