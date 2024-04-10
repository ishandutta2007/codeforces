#include <stdio.h>
#define MOD 1000000007
int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld",&a,&b);
	c=a*(a+1)/2;
	c%=MOD;
	d=b*(b-1)/2;
	d%=MOD;
	c*=b;
	c%=MOD;
	c*=d;
	c%=MOD;
	d=b*(b-1)/2;
	d%=MOD;
	d*=a;
	d%=MOD;
	printf("%I64d",(c+d)%MOD);
}