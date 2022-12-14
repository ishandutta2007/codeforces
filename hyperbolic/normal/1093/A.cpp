#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%2==0) printf("%d\n",a/2);
		else printf("%d\n",(a-3)/2+1);
	}
}