#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld",&a,&b);
		scanf("%lld%lld",&c,&d);
		
		
		long long int s1 = 0, s2 = 0;
		if(a>b) s1 = b*d + (a-b)*c;
		else s1 = a*d + (b-a)*c;
		s2 = (a+b)*c;
		printf("%lld\n",s1<s2?s1:s2);
	}
}