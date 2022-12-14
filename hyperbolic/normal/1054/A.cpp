#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int s = d*abs(a-b);
	int t = e*(abs(c-a)+abs(a-b))+3*f;
	printf("%s",t<=s?"YES":"NO");
}