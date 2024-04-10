#include <stdio.h>
int func(int k)
{
	if(k%400==0) return 366;
	else if(k%4==0)
	{
		if(k%100==0) return 365;
		else return 366;
	}
	else return 365;
}
int main()
{
	int a,s=0;
	scanf("%d",&a);
	for(int i=a;;i++)
	{
		s+=func(i);
		if(s%7==0&&func(a)==func(i+1))
		{
			printf("%d",i+1);
			return 0;
		}
	}
}