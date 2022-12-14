#include <stdio.h>
#include <algorithm>

int x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	printf("%d",x[(a+1)/2]);
}