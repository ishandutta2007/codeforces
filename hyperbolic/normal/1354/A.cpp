#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		
		if(a<=b)
		{
			printf("%lld\n",b);
			continue;
		}
		else
		{
			a -= b;
			if(c<=d)
			{
				printf("-1\n");
				continue;
			}
			else
			{
				long long int e = (a-1)/(c-d)+1;
				printf("%lld\n",b+e*c);
				continue;
			}
		}
	}
}