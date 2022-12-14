#include <stdio.h>

int main()
{
	int a,b,c0;
	scanf("%d:%d",&a,&b);
	int c = 60*a+b;
	c0 = 60*a+b;
	for(;;c++)
	{
		c%=1440;
		int d,e;
		d = c/60;
		e = c%60;
		if(d%10==e/10 && d/10==e%10)
		{
			printf("%d",(c-c0+14400)%1440);
			return 0;
		}
	}
}