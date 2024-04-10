#include <stdio.h>

int x[1010][1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				int sum = x[i][j];
				for(int k=1;k<=200;k++) if(1<=i+k&&i+k<=a&&1<=j+k&&j+k<=b) sum += x[i+k][j+k];
				for(int k=1;k<=200;k++) if(1<=i+k&&i+k<=a&&1<=j-k&&j-k<=b) sum += x[i+k][j-k];
				for(int k=1;k<=200;k++) if(1<=i-k&&i-k<=a&&1<=j+k&&j+k<=b) sum += x[i-k][j+k];
				for(int k=1;k<=200;k++) if(1<=i-k&&i-k<=a&&1<=j-k&&j-k<=b) sum += x[i-k][j-k];
				ans = ans>sum?ans:sum;
			}
		}
		printf("%d\n",ans);
	}
}