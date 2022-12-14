#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%I64d%I64d",&a,&b);
	if(a>30) printf("%I64d",b);
	else
	{
		c = (1<<a);
		printf("%I64d",b%c);
	}
}