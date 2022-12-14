#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>0)
	{
		if(a==d) printf("1");
		else printf("0");
	}
	else
	{
		if(c==0&&d==0) printf("1");
		else printf("0");
	}
}