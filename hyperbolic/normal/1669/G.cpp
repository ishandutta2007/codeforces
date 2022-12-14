#include <stdio.h>

char x[1010][1010],ans[1010][1010];
int count[1010][1010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a+1;i++) for(int j=1;j<=b;j++) count[i][j] = 0;
		
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		for(int j=1;j<=b;j++)
		{
			int p = a+1;
			for(int i=a;i>=1;i--)
			{
				if(x[i][j]=='o') p = i;
				if(x[i][j]=='*') count[p][j]++;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='o') ans[i][j] = 'o';
				else ans[i][j] = '.';
			}
		}
		
		for(int i=1;i<=a+1;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=1;k<=count[i][j];k++)
				{
					ans[i-k][j] = '*';
				}
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++) printf("%c",ans[i][j]);
			printf("\n");
		}
	}
}