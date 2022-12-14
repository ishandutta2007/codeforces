#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	long long int sum = 0;
	for(int i=a+b;i<=b+c;i++)
	{
		int m1 = a>i-c?a:i-c;
		int m2 = b<i-b?b:i-b;
		int m3 = i-1<d?i-1:d;
		if(m3>=c) sum += (long long int)(m2-m1+1)*(m3-c+1);
	}
	printf("%lld",sum);
}