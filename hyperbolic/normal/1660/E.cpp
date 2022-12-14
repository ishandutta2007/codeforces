#include <stdio.h>

char x[4010][4010];
int y[4010][4010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		int sum = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) sum += (x[i][j]-'0');
		
		for(int i=1;i<=2*a;i++) for(int j=1;j<=2*a;j++) x[i][j] = x[(i-1)%a+1][(j-1)%a+1];
		for(int i=1;i<=2*a;i++) for(int j=1;j<=2*a;j++) y[i][j] = x[i][j] - '0';
		for(int i=2*a-1;i>=1;i--) for(int j=1;j<2*a;j++) y[i][j] += y[i+1][j+1];
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				int t = y[i][j] - y[i+a][j+a];
				ans = ans>t?ans:t;
			}
		}
		
		printf("%d\n",sum+a-2*ans);
	}
}