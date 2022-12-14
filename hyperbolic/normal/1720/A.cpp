#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a*d==b*c) printf("0\n");
		else if(a==0) printf("1\n");
		else if(c==0) printf("1\n");
		else if((a*d)%(b*c)==0) printf("1\n");
		else if((b*c)%(a*d)==0) printf("1\n");
		else printf("2\n");
	}
}