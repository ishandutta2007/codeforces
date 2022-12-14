#include <stdio.h>

char x[110][110];
int y[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = 0;
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++) x[i][b+1] = '.';
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='*')
				{
					int control = 1;
					for(int k=1;k<=c;k++)
					{
						if(x[i-k][j-k]!='*')
						{
							control = 0;
							break;
						}
					}
					for(int k=1;k<=c;k++)
					{
						if(x[i-k][j+k]!='*')
						{
							control = 0;
							break;
						}
					}
					
					if(control==1)
					{
						y[i][j] = 1;
						for(int k=1;;k++)
						{
							if(x[i-k][j-k]=='*' && x[i-k][j+k]=='*') y[i-k][j-k] = y[i-k][j+k] = 1;
							else break;
						}
					}
				}
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='*'&&y[i][j]==0)
				{
					printf("NO\n");
					goto u;
				}
			}
		}
		printf("YES\n");
		u:;
	}
}