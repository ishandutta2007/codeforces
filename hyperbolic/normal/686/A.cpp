#include <stdio.h>

int main()
{
	int a;
	long long int b;
	int e = 0;
	scanf("%d %I64d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		char c;
		int d;
		scanf("\n%c %d",&c,&d);
		if(c=='+') b+=d;
		else if(c=='-')
		{
			if(b<d) e++;
			else b-=d;
		}
	}
	printf("%I64d %d",b,e);
}