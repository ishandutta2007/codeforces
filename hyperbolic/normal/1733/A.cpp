#include <stdio.h>

int val[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<b;i++) val[i] = 0;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			val[i%b] = val[i%b]>c?val[i%b]:c;
		}
		long long int ans = 0;
		for(int i=0;i<b;i++) ans += val[i];
		printf("%lld\n",ans);
	}
}