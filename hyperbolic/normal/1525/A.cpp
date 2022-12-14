#include <stdio.h>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int b = 100-a;
		int g = gcd(a,b);
		a/=g, b/=g;
		printf("%d\n",a+b);
	}
}