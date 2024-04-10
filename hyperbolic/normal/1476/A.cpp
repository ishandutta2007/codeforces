#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b<a)
		{
			int c = a/b;
			if(b*c==a) b = b*c;
			else b = b*(c+1);
		}
		if(b%a==0) printf("%d\n",b/a);
		else printf("%d\n",b/a+1);
	}
}