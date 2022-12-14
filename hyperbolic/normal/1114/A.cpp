#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int d,e,f;
	scanf("%d%d%d",&d,&e,&f);
	if(a>d)
	{
		printf("NO");
		return 0;
	}
	if(b>(d-a)+e)
	{
		printf("NO");
		return 0;
	}
	if(c>(d-a)+(e-b)+f)
	{
		printf("NO");
		return 0;
	}
	printf("YES");
}