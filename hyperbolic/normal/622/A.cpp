#include <stdio.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	for(int i=1;;i++)
	{
		if(a<=i)
		{
			printf("%lld",a);
			return 0;
		}
		else a -= i;
	}
}