#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		printf("%d\n",a-2<x[a-1]-1?a-2:x[a-1]-1);
	}
}