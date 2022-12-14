#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	if(b==0)
	{
		printf("%lld %lld",a,a);
		return 0;
	}
	
	long long int c,d;
	c = a-2*b;
	if(c<0) c = 0;
	for(long long int i=2;i<=a;i++)
	{
		if(i*(i-1)/2>=b)
		{
			d = (a-i);
			break;
		}
	}
	printf("%lld %lld",c,d);
}