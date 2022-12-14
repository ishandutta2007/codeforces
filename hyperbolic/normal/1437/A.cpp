#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(2*a>=(b+1)) printf("YES\n");
		else printf("NO\n");
	}
}