#include <stdio.h>
#include <algorithm>

int x[200010];
long long int sum[200010],check[200010];
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
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
		
		for(int i=1;i<=a;i++)
		{
			if(b-sum[i]<0) check[i] = 0;
			else check[i] = (b-sum[i])/i+1;
		}
		check[a+1] = 0;
		
		long long int ans = 0;
		for(int i=a;i>=1;i--) ans += i*(check[i]-check[i+1]);
		printf("%lld\n",ans);
	}
}