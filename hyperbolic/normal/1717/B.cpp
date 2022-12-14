#include <stdio.h>

char ans[1010][1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) ans[i][j] = '.';
		for(int i=c+d;i>=2;i-=b)
		{
			for(int j=1;j<=a;j++)
			{
				int k = i-j;
				if(1<=j&&j<=a&&1<=k&&k<=a) ans[j][k] = 'X';
			}
		}
		for(int i=c+d;i<=2*a;i+=b)
		{
			for(int j=1;j<=a;j++)
			{
				int k = i-j;
				if(1<=j&&j<=a&&1<=k&&k<=a) ans[j][k] = 'X';
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++) printf("%c",ans[i][j]);
			printf("\n");
		}
	}
}