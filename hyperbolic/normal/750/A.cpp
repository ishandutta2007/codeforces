#include <stdio.h>

int main()
{
	int a,b,s=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		if(5*i*(i+1)/2+b>240)
		{
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%d",a);
}