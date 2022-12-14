#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	long long int t = a/(2*(b+1));
	printf("%lld %lld %lld",t,b*t,a-(b+1)*t);
}