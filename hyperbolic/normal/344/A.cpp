#include <stdio.h>
char x[100010]={2},y[100010]={2,2};
int main()
{
	int a,i,count=0;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%s",x);
		if(y[1]==x[0]) count++;
		y[0]=x[0],y[1]=x[1];
	}
	printf("%d",count+1);
}