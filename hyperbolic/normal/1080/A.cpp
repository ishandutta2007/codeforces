#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int x,y,z;
	
	x = (a*2-1)/b+1;//k*x>=n*2
	y = (a*5-1)/b+1;
	z = (a*8-1)/b+1;
	printf("%d",x+y+z);
}