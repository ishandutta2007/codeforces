#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		for(long long int t=0;;t+=b)
		{
			if(2*t*t>a*a)
			{
				long long int s = t-b;
				if(s*s+(s+b)*(s+b)<=a*a) printf("Ashish\n");
				else printf("Utkarsh\n");
				break;
			}
		}
	}
}