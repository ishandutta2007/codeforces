#include <stdio.h>

int main()
{
	int a,b,c,i,count=0;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&c);
		if(c>b) count+=2;
		else count+=1;
	}
	printf("%d",count);
}