#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		int ans = 12345678;
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				int sum = 0;
				for(int k=1;k<=b;k++) sum += abs(x[i][k]-x[j][k]);
				ans = ans<sum?ans:sum;
			}
		}
		printf("%d\n",ans);
	}
}