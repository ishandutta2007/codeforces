#include<stdio.h>
int main()
{
	int a,b,i=1;
	scanf("%d%d",&a,&b);
	while(a>=0&&b>=0)
	{
		if(i%2==0)
		b-=i;
		else
		a-=i;
		i++;
		//printf("%d %d %d\n",a,b,i);
			}
	if(a<0)
	printf("Vladik");
	else
	printf("Valera");
	}