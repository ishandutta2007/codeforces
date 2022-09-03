#include<cstdio>

int chk(int x)
{
    int a,b,c,d;
    a=x/1000;
    b=x/100%10;
    c=x/10%10;
    d=x%10;
    return a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(!chk(++n));
	printf("%d",n);
}