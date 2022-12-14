#include <stdio.h>
#define MAX 123456789
int min(int a, int b)
{
	return a<b?a:b;
}
int max(int a, int b)
{
	return a>b?a:b;
}
int main()
{
	int a,b,c;
	int control1=0,control2=0;
	int m = -MAX,M = MAX;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d%d",&b,&c);
		if(c==1)
		{
			control1 = 1;
			m = max(1900,m);
			m+=b;
			M+=b;
		}
		else
		{
			control2 = 1;
			M = min(1899,M);
			m+=b;
			M+=b;
		}
	}
	if(m>M) printf("Impossible");
	else if(control2==1) printf("%d",M);
	else printf("Infinity");
}