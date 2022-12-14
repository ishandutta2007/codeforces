#include <stdio.h>

int main()
{
	long long int a;
	scanf("%I64d",&a);
	if(a%2==0)
	{
		long long int b = a/2;
		if(b==1) printf("-1");
		else printf("%I64d %I64d",b*b-1,b*b+1);
	}
	else if(a%2==1)
	{
		long long int b = a;
		if(b==1) printf("-1");
		else
		{
			printf("%I64d %I64d",(b*b-1)/2,(b*b+1)/2);
		}
	}
	// 2m m^2-1 m^2+1
	// 
}