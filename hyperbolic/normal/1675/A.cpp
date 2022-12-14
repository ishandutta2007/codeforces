#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		d -= a;
		d = d>0?d:0;
		e -= b;
		e = e>0?e:0;
		if(d+e<=c) printf("YES\n");
		else printf("NO\n");
	}
}