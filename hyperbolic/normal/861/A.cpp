#include <stdio.h>

int main()
{
	long long int a;
	int b;
	int two=0,five =0;
	scanf("%I64d%d",&a,&b);
	while(a%2==0)
	{
		two++;
		a/=2;
	}
	while(a%5==0)
	{
		five++;
		a/=5;
	}
	if(two<b) two = b;
	if(five<b) five = b;
	for(int i=1;i<=two;i++) a*=2;
	for(int i=1;i<=five;i++) a*=5;
	printf("%I64d",a);
}