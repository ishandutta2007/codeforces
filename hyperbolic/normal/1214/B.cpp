#include <stdio.h>

int main()
{
	int a,b,c;
	int count = 0;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=c;i++)
	{
		if(i<=b&&(c-i)<=a) count++;
	}
	printf("%d",count);
}