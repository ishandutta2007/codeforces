#include <stdio.h>
#define MOD 1000000007
int main()
{
	int a;
	scanf("%d",&a);
	
	long long int C1 = 1,C2=1;
	for(int i=1;i<=a;i++)
	{
		C1*=i;
		C1%=MOD;
	}
	for(int i=1;i<a;i++)
	{
		C2*=2;
		C2%=MOD;
	}
	printf("%lld",(C1-C2+MOD)%MOD);
}