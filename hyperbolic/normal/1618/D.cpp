#include <stdio.h>
#include <algorithm>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		long long int ans = 0;
		for(int i=a;i>=a-b+1;i--) ans += (x[i-b]/x[i]);
		for(int i=1;i<=a-2*b;i++) ans += x[i];
		printf("%lld\n",ans);
	}
}