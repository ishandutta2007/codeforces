#include <stdio.h>

int x[5010];
int y[5010][5010],z[5010][5010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=i;j++)
			{
				y[j][i] = y[j-1][i];
				if(x[j]<x[i]) y[j][i]++;
			}
		}
		for(int i=1;i<=a;i++) z[i][a+1] = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=a;j>=i;j--)
			{
				z[i][j] = z[i][j+1];
				if(x[i]>x[j]) z[i][j]++;
			}
		}
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				int t = y[i-1][j] * z[i][j+1];
				ans += t;
			}
		}
		printf("%lld\n",ans);
	}
}