#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=2;i<=a;i++) printf("%d ",i);
		printf("1\n");
	}
}