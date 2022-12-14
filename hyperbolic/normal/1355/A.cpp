#include <stdio.h>

int func(long long int k)
{
	int a = 10, b = -1;
	
	while(k)
	{
		a = a<k%10?a:k%10;
		b = b>k%10?b:k%10;
		k/=10;
	}
	return a*b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		
		long long int s = a;
		for(int i=1;i<=10000 && i<b;i++) s += func(s);
		printf("%lld\n",s);
	}
}