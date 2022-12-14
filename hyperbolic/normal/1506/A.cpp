#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		c--;
		long long int x = c/a;
		long long int y = c%a;
		printf("%lld\n",y*b+x+1);
	}
}