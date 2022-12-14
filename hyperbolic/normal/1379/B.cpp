#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		
		for(long long int i=a;i<=b;i++)
		{
			long long int k = c%i;
			if(k!=c)
			{
				if(a-b<=k&&k<=b-a)
				{
					for(long long int j=a;j<=b;j++)
					{
						if(a<=(j-k)&&(j-k)<=b)
						{
							printf("%lld %lld %lld\n",i,j,j-k);
							goto u;
						}
					}
				}
			}
			k -= i;
			if(a-b<=k&&k<=b-a)
			{
				for(long long int j=a;j<=b;j++)
				{
					if(a<=(j-k)&&(j-k)<=b)
					{
						printf("%lld %lld %lld\n",i,j,j-k);
						goto u;
					}
				}
			}
		}
		u:;
	}
}