#include <stdio.h>

int x[10010],DP[2010][3];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int min = 1, max = 2000;
		int ans = 2000;
		while(min<=max)
		{
			int h = (min+max)/2;
			for(int j=0;j<=h;j++) DP[j][0] = 1;
			for(int i=1;i<=a;i++)
			{
				for(int j=0;j<=h;j++) DP[j][i%2] = 0;
				for(int j=0;j+x[i]<=h;j++) if(DP[j][1-i%2]==1) DP[j+x[i]][i%2] = 1;
				for(int j=x[i];j<=h;j++) if(DP[j][1-i%2]==1) DP[j-x[i]][i%2] = 1;
			}
			
			for(int j=0;j<=h;j++)
			{
				if(DP[j][a%2]==1)
				{
					ans = h;
					max = h-1;
					goto u;
				}
			}
			min = h+1;
			u:;
		}
		printf("%d\n",ans);
	}
}