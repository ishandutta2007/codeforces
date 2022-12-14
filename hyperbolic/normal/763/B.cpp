#include <stdio.h>
#define MAX 1000000000

int main()
{
	int a;
	scanf("%d",&a);
	printf("YES\n");
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		b += MAX, c += MAX;
		int t = 2*(b%2) + (c%2);
		printf("%d\n",t+1);
	}
}