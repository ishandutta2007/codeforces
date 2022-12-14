#include <stdio.h>

int ans[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) ans[i][j] = 0;
		
		if((a+b)%2==0)
		{
			if(a%2==1)
			{
				for(int j=1;j<=b;j+=2) ans[1][j] = 1;
				for(int i=1;i<=a;i+=2) ans[i][b] = 1;
				for(int j=1;j<=b;j+=2) ans[a][j] = 1;
				for(int i=1;i<=a;i+=2) ans[i][1] = 1;
			}
			else
			{
				for(int j=1;j<=b-2;j+=2) ans[1][j] = 1;
				for(int i=1;i<=a-2;i+=2) ans[i][b] = 1;
				for(int j=b;j>=3;j-=2) ans[a][j] = 1;
				for(int i=a;i>=3;i-=2) ans[i][1] = 1;
			}
		}
		else
		{
			if(b%2==0)
			{
				for(int i=1;i<=a;i+=2) ans[i][1] = ans[i][b] = 1;
				for(int j=3;j<=b-2;j+=2) ans[1][j] = ans[a][j] = 1; 
			}
			else
			{
				for(int j=1;j<=b;j+=2) ans[1][j] = ans[a][j] = 1;
				for(int i=3;i<=a-2;i+=2) ans[i][1] = ans[i][b] = 1;
 			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
}