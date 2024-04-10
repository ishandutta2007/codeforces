#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(2*a==a+b+c) printf("YES\n");
		else if(2*b==a+b+c) printf("YES\n");
		else if(2*c==a+b+c) printf("YES\n");
		else printf("NO\n");
	}
}