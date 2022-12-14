#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<b-(a-b);i++) printf("%d ",i);
		for(int i=b-(a-b);i<=b;i++) printf("%d ",b+b-(a-b)-i);
		printf("\n");
	}
}