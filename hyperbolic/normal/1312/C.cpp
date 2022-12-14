#include <stdio.h>

long long int x[100010];
int check[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=0;i<=60;i++) check[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<=60;j++)
			{
				check[j] += (x[i]%b);
				x[i]/=b;
			}
		}
		for(int j=0;j<=60;j++)
		{
			if(check[j]>=2)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}