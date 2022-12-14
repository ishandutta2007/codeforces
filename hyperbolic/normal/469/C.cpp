#include <stdio.h>

int main()
{
	int a,i;
	scanf("%d",&a);
	if(a<=3)
	{
		printf("NO");
		return 0;
	}
	if(a==4)
	{
		printf("YES\n");
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24");
		return 0;
	}
	if(a==5)
	{
		printf("YES\n");
		printf("5 + 1 = 6\n");
		printf("6 - 2 = 4\n");
		printf("4 + 4 = 8\n");
		printf("3 * 8 = 24");
		return 0;
	}
	if(a>=6)
	{
		printf("YES\n");
		printf("%d - %d = 1\n",a,a-1);
		printf("1 - 1 = 0\n");
		for(i=a-2;i>=5;i--) printf("0 * %d = 0\n",i);
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
		printf("24 + 0 = 24");
	}
}