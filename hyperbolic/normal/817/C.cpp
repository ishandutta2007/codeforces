#include <stdio.h>

long long int func(long long int k)
{
	if(k==0) return 0;
	else return k%10 + func(k/10);
}

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	long long int p = a+1;
	long long int min = 1, max = a;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		if(h-func(h)<b) min = h+1;
		else
		{
			p = h;
			max = h-1;
		}
	}
	printf("%lld",a-p+1);
}