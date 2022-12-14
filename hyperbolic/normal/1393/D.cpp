#include <stdio.h>

int check[2010][2010];
int sum1[2010][2010],sum2[2010][2010];
char x[2010][2010];

int func(int s, int t, int k)
{
	if(sum1[s][t-k]<k+1) return 0;
	if(sum1[s+k][t]<k+1) return 0;
	if(sum2[s][t+k]<k+1) return 0;
	if(sum2[s+k][t]<k+1) return 0;
	return 1;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			sum1[i][j] = 1;
			sum2[i][j] = 1;
		}
	}
	
	for(int i=2;i<=a;i++) for(int j=1;j<b;j++) if(x[i][j]==x[i-1][j+1]) sum1[i][j] = sum1[i-1][j+1]+1;
	for(int i=2;i<=a;i++) for(int j=2;j<=b;j++) if(x[i][j]==x[i-1][j-1]) sum2[i][j] = sum2[i-1][j-1]+1;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			check[i][j] = check[i][j-1]>check[i-1][j]?check[i][j-1]:check[i-1][j];
			check[i][j]--;
			if(check[i][j]<0) check[i][j] = 0;
			while(1)
			{
				int k = check[i][j]+1;
				if(i-k<1) break;
				if(i+k>a) break;
				if(j-k<1) break;
				if(j+k>b) break;
				if(x[i-k][j]!=x[i][j]) break;
				if(!func(i,j,k)) break;
				check[i][j]++;
			}
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) ans += (check[i][j]+1);
	printf("%lld",ans);
}