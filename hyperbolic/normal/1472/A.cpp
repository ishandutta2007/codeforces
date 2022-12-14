#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int d = 1, e = 1;
		while(a%2==0)
		{
			a/=2;
			d*=2;
		}
		while(b%2==0)
		{
			b/=2;
			e*=2;
		}
		printf("%s\n",d*e>=c?"YES":"NO");
	}
}