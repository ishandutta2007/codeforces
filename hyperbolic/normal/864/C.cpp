#include <stdio.h>
#define MIN -1234567
int a,b,c,d;
int func2(int gas, int count);
int func1(int gas, int count)
{
	if(count==1)
	{
		if(c>gas) return MIN;
		else if((a-c)>b) return MIN;
		else if(a>gas) return 1;
		else return 0;
	}
	if(c>gas) return MIN;
	if(a+(a-c)>gas) return func2(b-(a-c),count-1)+1;
	else return func2(gas-a,count-1);
}
int func2(int gas, int count)
{
	if(count==1)
	{
		if(a-c>gas) return MIN;
		else if(c>b) return MIN;
		else if(a>gas) return 1;
		else return 0;
	}
	if((a-c)>gas) return MIN;
	if(a+c>gas) return func1(b-c,count-1)+1;
	else return func1(gas-a,count-1);
}
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d",func1(b,d)<0?-1:func1(b,d));
}