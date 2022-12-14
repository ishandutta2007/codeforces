#include <stdio.h>

void func(int k)
{
	if(k==4)
	{
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
	}
	else if(k==5)
	{
		printf("5 - 1 = 4\n");
		printf("4 - 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
	}
	else if(k==6)
	{
		printf("4 + 6 = 10\n");
		printf("10 - 5 = 5\n");
		printf("5 - 1 = 4\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
	}
	else if(k==7)
	{
		printf("5 + 7 = 12\n");
		printf("12 - 6 = 6\n");
		printf("6 - 3 = 3\n");
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
	}
	else
	{
		printf("%d - %d = 1\n",k,k-1);
		printf("%d - %d = 1\n",k-2,k-3);
		printf("1 - 1 = 0\n");
		func(k-4);
		printf("24 + 0 = 24\n");
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	if(a<=3) printf("NO");
	else
	{
		printf("YES\n");
		func(a);
	}
}