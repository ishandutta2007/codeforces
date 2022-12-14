#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	if(2*a-1<b)
	{
		printf("0");
		return 0;
	}
	else
	{
		long long int min = 1>b-a?1:b-a;
		long long int max;
		if(b%2==0) max = (b/2)-1;
		else max = (b/2);
		printf("%lld",max-min+1);
	}
}