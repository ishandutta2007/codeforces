#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	long long int c,d;
	scanf("%lld%lld",&c,&d);
	
	long long int min = a*b, max = 1;
	
	long long int start;
	start = c+1;
	for(int i=2;i<=a+2;i++)
	{
		long long int end = (i-1)*b+d+1;
		long long int g = gcd(a*b,end-start);
		min = min<(a*b)/g?min:(a*b)/g;
		max = max>(a*b)/g?max:(a*b)/g;
	}
	
	start = c+1;
	for(int i=2;i<=a+2;i++)
	{
		long long int end = (i)*b+1-d;
		long long int g = gcd(a*b,end-start);
		min = min<(a*b)/g?min:(a*b)/g;
		max = max>(a*b)/g?max:(a*b)/g;
	}
	
	start = b+1-c;
	for(int i=2;i<=a+2;i++)
	{
		long long int end = (i-1)*b+d+1;
		long long int g = gcd(a*b,end-start);
		min = min<(a*b)/g?min:(a*b)/g;
		max = max>(a*b)/g?max:(a*b)/g;
	}
	
	start = b+1-c;
	for(int i=2;i<=a+2;i++)
	{
		long long int end = (i)*b+1-d;
		long long int g = gcd(a*b,end-start);
		min = min<(a*b)/g?min:(a*b)/g;
		max = max>(a*b)/g?max:(a*b)/g;
	}
	
	printf("%lld %lld",min,max);
}