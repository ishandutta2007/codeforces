#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(b==1) printf("NO\n");
		else
		{
			printf("YES\n");
			printf("%lld %lld %lld\n",a,a*(2*b-1),a*b*2);
		}
	}
}