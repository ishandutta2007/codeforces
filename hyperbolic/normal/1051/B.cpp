#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	printf("YES\n");
	for(long long int p=a;p<=b;p+=2) printf("%lld %lld\n",p,p+1);
}