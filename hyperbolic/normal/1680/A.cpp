#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int e = a>c?a:c;
		int f = b<d?b:d;
		if(e<=f) printf("%d\n",e);
		else printf("%d\n",a+c);
	}
}