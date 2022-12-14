#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d:%d",&a,&b);
	int c = 60*a+b;
	int d;
	scanf("%d",&d);
	c += d;
	while(c>=1440) c -= 1440;
	printf("%02d:%02d",c/60,c%60);
}