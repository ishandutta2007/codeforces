#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(b<a)
		{
			long long int s = (b+1)*b/2;
			printf("%lld\n",s);
		}
		else
		{
			long long int s = (a)*(a-1)/2;
			printf("%lld\n",s+1);
		}
	}
}