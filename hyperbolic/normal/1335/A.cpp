#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int m = 1, M = (a-1)/2;
		printf("%d\n",M-m+1);
	}
}