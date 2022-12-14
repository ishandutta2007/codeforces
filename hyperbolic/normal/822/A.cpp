#include <stdio.h>
int min(int a, int b)
{
	return a<b?a:b;
}
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c = min(a,b);
	int ans = 1;
	for(int i=1;i<=c;i++) ans*=i;
	printf("%d",ans);
}