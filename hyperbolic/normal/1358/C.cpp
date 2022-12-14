#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
		c-=a, d-=b;
		if(c>d)
		{
			int t = d;
			d = c;
			c = t;
		}
		printf("%lld\n",(long long int)c*d+1);
	}
}