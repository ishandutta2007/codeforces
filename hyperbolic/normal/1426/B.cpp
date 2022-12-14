#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int control = 0;
		for(int i=1;i<=a;i++)
		{
			int c,d,e,f;
			scanf("%d%d%d%d",&c,&d,&e,&f);
			if(d==e) control = 1;
		}
		if(b%2==1) printf("NO\n");
		else if(control==1) printf("YES\n");
		else printf("NO\n");
	}
}