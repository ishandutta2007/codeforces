#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if((a+b)%3!=0) printf("NO\n");
		else
		{
			int c = (a+b)/3;
			if(a>=c && b>=c) printf("YES\n");
			else printf("NO\n");
		}
	}
}