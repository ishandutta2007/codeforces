#include <stdio.h>
int x[20]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
int main()
{
	int a,s=0;
	scanf("%d",&a);
	if(a==0)
	{
		printf("1");
		return 0;
	}
	while(a)
	{
		s+=x[a%16];
		a/=16;
	}
	printf("%d",s);
}