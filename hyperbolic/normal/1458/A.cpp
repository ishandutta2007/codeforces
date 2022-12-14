#include <stdio.h>
#include <algorithm>
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int x[200010],y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=b;i++) scanf("%lld",&y[i]);
	
	long long int m = 0;
	for(int i=1;i<a;i++) m = gcd(m,x[i+1]-x[i]);
	for(int i=1;i<=b;i++)
	{
		printf("%lld ",gcd(m,x[1]+y[i]));
	}
}