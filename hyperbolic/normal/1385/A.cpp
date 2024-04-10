#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==b&&b==c)
		{
			printf("YES\n");
			printf("%d %d %d\n",a,a,a);
		}
		else if(a==b&&b>c)
		{
			printf("YES\n");
			printf("%d %d %d\n",a,c,c);
		}
		else if(b==c&&b>a)
		{
			printf("YES\n");
			printf("%d %d %d\n",b,a,a);
		}
		else if(a==c&&a>b)
		{
			printf("YES\n");
			printf("%d %d %d\n",a,b,b);
		}
		else printf("NO\n");
	}
}