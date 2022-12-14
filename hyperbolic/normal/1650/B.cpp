#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int d = (b/c) + (b%c);
		int e = 0;
		if((b/c-1)*c+(c-1)>=a) e = (b/c-1) + (c-1);
		printf("%d\n",d>e?d:e);
	}
}