#include<cstdio>

int main()
{
	int tux;
	scanf("%d",&tux);
	int foo=0,bar=0,baz=0,quz=1,pur;
	while(tux--)
	{
		scanf("%d",&pur);
		foo=foo+pur;
		bar=bar+1;
		if(foo*quz>=bar*baz||(foo*quz<bar*baz&&bar*baz==foo*quz))
		{
			baz=foo;
			quz=bar;
		}
	}
	printf("%lf",1.*baz/quz);
}