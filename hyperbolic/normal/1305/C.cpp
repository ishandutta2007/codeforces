#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}
int x[200010];
int check[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&x[i]);
		check[x[i]%b]++;
	}
	for(int i=0;i<b;i++)
	{
		if(check[i]>=2)
		{
			printf("0");
			return 0;
		}
	}
	
	long long int ans = 1;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			ans *= abs(x[j]-x[i]);
			ans %= b;
		}
	}
	printf("%lld",ans);
}