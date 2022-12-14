#include <stdio.h>
#define MAX 1000000

int x[110];
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int DP[3][1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int g = 0;
	for(int i=1;i<=a;i++) g = gcd(g,x[i]);
	while(g%2==0)
	{
		g/=2;
		for(int i=1;i<=a;i++) x[i]/=2;
	}
	
	int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	if(sum%2==1) printf("0");
	else
	{
		DP[0][0] = 1;
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<=MAX;j++) DP[i%2][j] = 0;
			for(int j=0;j<=MAX;j++)
			{
				if(DP[(i-1)%2][j]==1)
				{
					DP[i%2][j] = 1;
					if(j+x[i]<=MAX) DP[i%2][j+x[i]] = 1;
				}
			}
		}
		if(DP[a%2][sum/2]==1)
		{
			for(int i=1;i<=a;i++)
			{
				if(x[i]%2==1)
				{
					printf("1\n%d",i);
					return 0;
				}
			}
		}
		printf("0");
	}
}