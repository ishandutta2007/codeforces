#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)
		{
			int t = a;
			a = b;
			b = t;
		}
		int c = 2*a>b?2*a:b;
		printf("%d\n",c*c);
	}
}