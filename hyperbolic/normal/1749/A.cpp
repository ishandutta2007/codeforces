#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
		}
		if(b==1)
		{
			if(a==1) printf("NO\n");
			else printf("YES\n");
		}
		else if(a==b) printf("NO\n");
		else printf("YES\n");
	}
}