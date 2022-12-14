#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		if(b>c) printf("%d %d\n",b-1,c);
		else printf("%d %d\n",b-1,c);
	}
}