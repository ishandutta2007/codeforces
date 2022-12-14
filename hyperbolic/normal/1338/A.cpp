#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int p = x[1];
		int ans = 0;
		for(int i=2;i<=a;i++)
		{
			p = p>x[i]?p:x[i];
			int t = p-x[i];
			int count = 0;
			while(t) count++, t/=2;
			ans = ans>count?ans:count;
		}
		printf("%d\n",ans);
	}
}