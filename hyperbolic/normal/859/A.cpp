#include <stdio.h>

int main()
{
	int a,b,m=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b);
		m = m>b?m:b;
	}
	if(m>=25) printf("%d ",m-25);
	else printf("0");
}