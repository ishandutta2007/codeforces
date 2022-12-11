#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h,a,b;
	scanf("%d%d:%d",&h,&a,&b);
	if (h==12)
	{
		if (a==0) printf("01");
		else if (a<=12) printf("%02d",a);
		else if (a%10!=0) printf("0%d",a%10);
		else printf("10");
	}
	else
	{
		if (a<24) printf("%02d",a);
		else printf("0%d",a%10);
	}
	putchar(':');
	if (b<60) printf("%02d",b);
	else printf("0%d",b%10);
	return 0;
}