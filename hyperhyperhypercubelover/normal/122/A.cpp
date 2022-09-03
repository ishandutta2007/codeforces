#include<cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	if(n%4==0)puts("YES");
	else if(n%7==0)puts("YES");
	else if(n%47==0)puts("YES");
	else if(n%74==0)puts("YES");
	else if(n%447==0)puts("YES");
	else if(n%474==0)puts("YES");
	else if(n%477==0)puts("YES");
	else if(n%744==0)puts("YES");
	else if(n%747==0)puts("YES");
	else if(n%774==0)puts("YES");
	else puts("NO");
}