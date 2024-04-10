#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		a--,b--;
		if(a>31) printf("YES %lld\n",a);
		else
		{
			long long int d = 1;
			for(int j=1;j<=a;j++) d*=4;
			
			long long int left = (d-1)/3;
			if(left>=b)
			{
				printf("YES %lld\n",a);
				continue;
			}
			
			long long int e = 1;
			for(long long int i=1;i<=a;i++)
			{
				if(b<=(1<<(i+1))-2)
				{
					printf("NO\n");
					goto u;
				}
				b -= ((1<<(i+1))-1);
				e = 2*e+3;
				d /= 4;
				
				if(left>=b-e*((d-1)/3))
				{
					printf("YES %lld\n",a-i);
					goto u;
				}
				left += e*((d-1)/3);
			}
			printf("NO\n");
			u:;
		}
	}
}