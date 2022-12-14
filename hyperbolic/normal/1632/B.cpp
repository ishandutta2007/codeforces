#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int b = 1;
		while(b<=a-1) b*=2;
		b/=2;
		
		for(int i=1;i<b;i++) printf("%d ",i);
		printf("0 ");
		for(int i=b;i<a;i++) printf("%d ",i);
		printf("\n");
	}
}