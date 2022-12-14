#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b) printf("%d\n",a+b);
		else
		{
			int c = a>b?a:b;
			printf("%d\n",2*c-1);
		}
	}
}