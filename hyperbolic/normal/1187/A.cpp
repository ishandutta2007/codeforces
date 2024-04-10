#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		int e = c+d-b;
		printf("%d\n",(c-e>d-e?c-e:d-e)+1);
	}
}