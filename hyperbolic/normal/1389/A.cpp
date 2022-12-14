#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(2*a<=b) printf("%d %d\n",a,2*a);
		else printf("-1 -1\n");
	}
}