#include <stdio.h>
#include <math.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	long long int S = 2*(a+b);
	double k = sqrt(S);
	long long int start = (long long int)k-2;
	if(start<0) start = 0;
	for(long long int i=start;;i++)
	{
		if(i*(i+3)==S)
		{
			printf("%lld",a-i);
			return 0;
		}
	}
}