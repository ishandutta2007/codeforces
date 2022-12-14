#include <stdio.h>
#include <algorithm>
int x[10];
int main()
{
	scanf("%d%d%d",&x[1],&x[2],&x[3]);
	std::sort(x+1,x+4);
	printf("%d",x[3]-x[1]);
}