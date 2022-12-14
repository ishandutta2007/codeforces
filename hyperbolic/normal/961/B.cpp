#include <stdio.h>

long long int x[100010],y[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		if(c==1) y[i] = x[i];
		else y[i] = 0;
	}
	
	for(int i=1;i<=a;i++) x[i] += x[i-1];
	for(int i=1;i<=a;i++) y[i] += y[i-1];
	
	long long int ans = 0;
	for(int i=1;i+b-1<=a;i++)
	{
		long long int s = y[i-1] + (x[i+b-1]-x[i-1]) + (y[a]-y[i+b-1]);
		ans = ans>s?ans:s;
	}
	printf("%lld",ans);
}