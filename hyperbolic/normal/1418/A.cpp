#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long int s = b*c+c-1;
		printf("%lld\n",c+(s-1)/(a-1)+1);
	}
}