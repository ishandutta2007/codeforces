#include <stdio.h>
#include <algorithm>

int x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		printf("%d\n",x[a]+x[a-1]);
	}
}