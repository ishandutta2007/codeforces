#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(b>d+6) printf(">\n");
		else if(d>b+6) printf("<\n");
		else
		{
			while(b>d) a*=10, b--;
			while(d>b) c*=10, d--;
			if(a>c) printf(">\n");
			else if(a<c) printf("<\n");
			else printf("=\n");
		}
	}
}