#include <stdio.h>

long long int MAX = 1;
int a,b;
long long int x[110][110];
long long int check[110][110],sum[110][110];
int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%lld",&x[i][j]);
		
		long long int ans = MAX;
		for(int x0=1;x0<=a;x0++)
		{
			for(int y0=1;y0<=b;y0++)
			{
				for(int i=1;i<=x0;i++)
				{
					for(int j=1;j<=y0;j++)
					{
						sum[i][j] = MAX;
						long long int h = x[x0][y0] + (i-x0) + (j-y0);
						if(x[i][j]<h) check[i][j] = MAX;
						else check[i][j] = x[i][j]-h;
					}
				}
				for(int i=x0;i<=a;i++)
				{
					for(int j=y0;j<=b;j++)
					{
						sum[i][j] = MAX;
						long long int h = x[x0][y0] + (i-x0) + (j-y0);
						if(x[i][j]<h) check[i][j] = MAX;
						else check[i][j] = x[i][j]-h;
					}
				}
				
				sum[x0][y0] = 0;
				for(int i=x0+y0;i>=2;i--)
				{
					for(int j=1;j<=x0;j++)
					{
						//j,i-j
						if(i-j<=y0 && i-j>=1)
						{
							if(check[j][i-j]==MAX) continue;
							else
							{
								sum[j-1][i-j] = sum[j-1][i-j]<sum[j][i-j] + check[j-1][i-j]?sum[j-1][i-j]:sum[j][i-j] + check[j-1][i-j];
								sum[j][i-j-1] = sum[j][i-j-1]<sum[j][i-j] + check[j][i-j-1]?sum[j][i-j-1]:sum[j][i-j] + check[j][i-j-1];
							}
						}
					}
				}
				for(int i=x0+y0;i<=a+b;i++)
				{
					for(int j=x0;j<=a;j++)
					{
						//j,i-j
						if(i-j<=b && i-j>=y0)
						{
							if(check[j][i-j]==MAX) continue;
							else
							{
								sum[j+1][i-j] = sum[j+1][i-j]<sum[j][i-j] + check[j+1][i-j]?sum[j+1][i-j]:sum[j][i-j] + check[j+1][i-j];
								sum[j][i-j+1] = sum[j][i-j+1]<sum[j][i-j] + check[j][i-j+1]?sum[j][i-j+1]:sum[j][i-j] + check[j][i-j+1];
							}
						}
					}
				}
				
				ans = ans<sum[1][1]+sum[a][b]?ans:sum[1][1]+sum[a][b];
			}
		}
		printf("%lld\n",ans);
	}
}