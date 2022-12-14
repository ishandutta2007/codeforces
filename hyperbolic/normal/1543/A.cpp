#include <stdio.h>

long long int abs(long long int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(a==b) printf("0 0\n");
		else
		{
			long long int c = abs(a-b);
			long long int d1 = b%c;
			long long int d2 = c-d1;
			printf("%lld %lld\n",c,d1<d2?d1:d2);
		}
	}
}