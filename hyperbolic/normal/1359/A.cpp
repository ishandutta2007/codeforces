#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int d = a/c;
		if(d>=b) printf("%d\n",b);
		else printf("%d\n",d-((b-d-1)/(c-1)+1));
	}
}