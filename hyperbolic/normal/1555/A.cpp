#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		long long int b = (a+1)/2;
		if(b<=2) printf("15\n");
		else printf("%lld\n",5*b);
	}
}