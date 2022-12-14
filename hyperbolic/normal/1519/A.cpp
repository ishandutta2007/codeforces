#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a>=b)
		{
			if(a<=(c+1)*b) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			if(b<=(c+1)*a) printf("YES\n");
			else printf("NO\n");
		}
	}
}