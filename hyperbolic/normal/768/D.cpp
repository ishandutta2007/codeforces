#include <stdio.h>

int a;
double DP[10010][1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	DP[0][0] = 1;
	for(int i=1;i<=10000;i++) for(int j=1;j<=a;j++) DP[i][j] = (double)j/a * DP[i-1][j] + (double)(a-j+1)/a * DP[i-1][j-1];
	
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=10000;j++)
		{
			if(DP[j][a]*2000>=(double)c)
			{
				printf("%d\n",j);
				break;
			}
		}
	}
}