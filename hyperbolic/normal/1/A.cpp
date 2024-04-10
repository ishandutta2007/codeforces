#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d",&a,&b,&c);
	d=(a-1)/c+1;
	e=(b-1)/c+1;
	printf("%I64d",(long long int)d*e);
}