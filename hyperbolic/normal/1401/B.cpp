#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		if(c>e)
		{
			int ans = 2*e;
			if(f>a+(c-e)) ans -= 2*(f-a-(c-e));
			printf("%d\n",ans);
		}
		else
		{
			int ans = 2*c;
			if(f>a) ans -= 2*(f-a);
			printf("%d\n",ans);
		}
	}
}