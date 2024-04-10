#include<cstdio>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	while(--c)
	{
		b+=a;
		a=b-a;
	}
	printf("%d",b);
}