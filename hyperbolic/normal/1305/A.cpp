#include <stdio.h>
#include <algorithm>

int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+a+1);
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
		for(int i=1;i<=a;i++) printf("%d ",y[i]);
		printf("\n");
	}
}