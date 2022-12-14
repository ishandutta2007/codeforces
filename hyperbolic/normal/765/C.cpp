#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(b<a && c<a) printf("-1");
	else if(c<a)
	{
		if(b%a==0) printf("%d",b/a);
		else printf("-1");
	}
	else if(b<a)
	{
		if(c%a==0) printf("%d",c/a);
		else printf("-1");
	}
	else printf("%d",b/a+c/a);
	
}