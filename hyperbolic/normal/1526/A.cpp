#include <stdio.h>
#include <algorithm>

int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+2*a+1);
		for(int i=1;i<=a;i++) y[2*i-1] = x[i];
		for(int i=a+1;i<=2*a;i++) y[2*(i-a)] = x[i];
		
		for(int i=1;i<=2*a;i++) printf("%d ",y[i]);
		printf("\n");
	}
}