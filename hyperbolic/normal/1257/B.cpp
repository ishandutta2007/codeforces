#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==1)
		{
			if(b==1) printf("YES\n");
			else printf("NO\n");
		}
		else if(a<=3)
		{
			if(b<=3) printf("YES\n");
			else printf("NO\n");
		}
		else printf("YES\n");
	}
}