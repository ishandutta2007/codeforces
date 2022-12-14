#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(c>d)
		{
			int t = c;
			c = d;
			d = t;
		}
		int S = (c-1) + (a-d);
		if(b<S) printf("%d\n",(d-c)+b);
		else printf("%d\n",a-1);
	}
}