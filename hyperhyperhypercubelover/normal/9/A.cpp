#include<cstdio>
#include<algorithm>

int main()
{
	int i;
	int a,b;
    scanf("%d%d",&a,&b);
    a=7-std::max(a,b);
    b=6;
    if(a%2==0&&b%2==0)
	{
		a/=2;
		b/=2;
	}
    if(a%3==0&&b%3==0)
	{
		a/=3;
		b/=3;
	}
	printf("%d/%d",a,b);
}