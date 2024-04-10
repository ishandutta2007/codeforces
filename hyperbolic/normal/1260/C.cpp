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
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int d = gcd(a,b);
		a/=d, b/=d;
		if((b+a-2)/a>=c) printf("REBEL\n");
		else if((a+b-2)/b>=c) printf("REBEL\n");
		else printf("OBEY\n");
	}
}