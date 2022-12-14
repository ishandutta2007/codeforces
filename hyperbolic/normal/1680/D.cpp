#include <stdio.h>

long long int abs(long long int k)
{
	return k>0?k:-k;
}

long long int x[3010],check[3010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) if(x[i]==0) check[i] = 1;
	for(int i=1;i<=a;i++) check[i] += check[i-1];
	for(int i=1;i<=a;i++) x[i] += x[i-1];
	
	if(-check[a]*b <= x[a] && x[a]<=check[a]*b);
	else
	{
		printf("-1");
		return 0;
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			long long int max = x[i] + check[i]*b;
			long long int min = -(x[a]-x[j]) - (check[a]-check[j])*b;
			long long int gap = abs((x[j]-x[i])-(check[j]-check[i])*b);
			max = max>0?max:0;
			min = min<0?min:0;
			gap = gap<max-min?gap:max-min;
			ans = ans>gap?ans:gap;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			long long int min = x[i] - check[i]*b;
			long long int max = -(x[a]-x[j]) + (check[a]-check[j])*b;
			long long int gap = abs((x[j]-x[i])+(check[j]-check[i])*b);
			max = max>0?max:0;
			min = min<0?min:0;
			gap = gap<max-min?gap:max-min;
			ans = ans>gap?ans:gap;
		}
	}
	printf("%lld",ans+1);
}