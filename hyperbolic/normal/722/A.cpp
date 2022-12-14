#include <stdio.h>

char x[10];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	if(a==12)
	{
		if(x[1]=='0'&&x[2]=='0') x[2] = '1';
		else if(x[1]=='1'&&x[2]>='3') x[1] = '0';
		else if(x[1]>='2'&&x[2]>='1') x[1] = '0';
		else if(x[1]>='2'&&x[2]=='0') x[1] = '1';
		if(x[4]>='6') x[4] = '0';
	}
	else
	{
		if(x[1]>='3') x[1] = '0';
		else if(x[1]=='2'&&x[2]>='4') x[1] = '0';
		if(x[4]>='6') x[4] = '0';
	}
	printf("%s",x+1);
}