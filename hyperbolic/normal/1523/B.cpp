#include <stdio.h>

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
		
		printf("%d\n",3*a);
		for(int i=1;i<=a;i+=2)
		{
			printf("1 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
			printf("1 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
			printf("1 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
		}
	}
}