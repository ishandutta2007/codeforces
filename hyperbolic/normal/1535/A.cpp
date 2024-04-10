#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>b&&c>d)
		{
			if(b>c) printf("NO\n");
			else if(d>a) printf("NO\n");
			else printf("YES\n");
		}
		if(a>b&&c<d)
		{
			if(b>d) printf("NO\n");
			else if(c>a) printf("NO\n");
			else printf("YES\n");
		}
		if(a<b&&c>d)
		{
			if(a>c) printf("NO\n");
			else if(d>b) printf("NO\n");
			else printf("YES\n");
		}
		if(a<b&&c<d)
		{
			if(a>d) printf("NO\n");
			else if(c>b) printf("NO\n");
			else printf("YES\n");
		}
	}
}