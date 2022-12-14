#include <stdio.h>

int main()
{
	int a,b,c;
	int s1 = 0, s2 = 0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d%d",&b,&c);
		if(b>c) s1++;
		else if(b<c) s2++;
	}
	if(s1>s2)
	{
		printf("Mishka");
		return 0;
	}
	else if(s1<s2)
	{
		printf("Chris");
		return 0;
	}
	else
	{
		printf("Friendship is magic!^^");
		return 0;
	}
}