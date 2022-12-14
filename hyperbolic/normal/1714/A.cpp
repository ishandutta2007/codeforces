#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int t = 60*b+c;
		int ans = 12345678;
		while(a--)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			int s = 60*d+e;
			if(t<=s) ans = ans<s-t?ans:s-t;
			s += 1440;
			if(t<=s) ans = ans<s-t?ans:s-t;
		}
		printf("%d %d\n",ans/60,ans%60);
	}
}