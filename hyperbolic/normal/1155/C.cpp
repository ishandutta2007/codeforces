#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int x[300010],y[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=b;i++) scanf("%lld",&y[i]);
	long long int g = 0;
	for(int i=1;i<a;i++) g = gcd(g,x[i+1]-x[i]);
	
	for(int i=1;i<=b;i++)
	{
		if(g%y[i]==0)
		{
			printf("YES\n");
			printf("%lld %d",x[1],i);
			return 0;
		}
	}
	printf("NO");
}