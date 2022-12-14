#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		long long int b = a;
		long long int C = 1;
		while(b%2==0) b/=2, C*=2;
		if(C<2e9 && C*(2*C-1)<a) printf("%lld\n",2*C);
		else if(b!=1) printf("%lld\n",b);
		else printf("-1\n");
	}
}