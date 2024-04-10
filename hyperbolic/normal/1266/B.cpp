#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		if(b<=14) printf("NO\n");
		else if(1<=b%14&&b%14<=6) printf("YES\n");
		else printf("NO\n");
	}
}