#include <stdio.h>

int main()
{
	int a;
	int M = 123456789;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int width = i;
		int height = (a-1)/i+1;
		M = M<2*(width+height)?M:2*(width+height);
	}
	printf("%d",M);
}