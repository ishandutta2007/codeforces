#include <stdio.h>

int main()
{
	int a,i,b,s=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b);
		if(b-s<=15) s = b;
		else
		{
			printf("%d",s+15);
			return 0;
		}
	}
	printf("%d",s+15<90?s+15:90);
}