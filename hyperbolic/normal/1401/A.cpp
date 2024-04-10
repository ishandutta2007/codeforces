#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b) printf("%d\n",b-a);
		else printf("%d\n",(a-b)%2);
	}
}