#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			ans += c;
		}
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) ans += x[i];
		long long int max = x[1];
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		printf("%lld\n",ans-max);
	}
}