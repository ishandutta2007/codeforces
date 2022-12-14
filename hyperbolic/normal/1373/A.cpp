#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long int s1, s2;
		if(a<c) s1 = 1;
		else s1 = -1;
		if(c<a*b) s2 = b;
		else s2 = -1;
		printf("%lld %lld\n",s1,s2);
	}
}