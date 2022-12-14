#include <stdio.h>

int sum[400010],x[400010],check[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=2*b+1;i++) sum[i] = check[i] = 0;
		for(int i=1;i<=a/2;i++)
		{
			int s = x[i] + b > x[a-i+1]+b? x[i]+b : x[a-i+1]+b;
			int t = x[i] + 1 < x[a-i+1]+1? x[i]+1 : x[a-i+1]+1;
			
			check[2] += 2;
			check[t] += -1;
			check[x[i]+x[a-i+1]] += -1;
			check[x[i]+x[a-i+1]+1] += 1;
			check[s+1] += 1;
		}
		
		for(int i=2;i<=2*b;i++) sum[i] = sum[i-1] + check[i];
		
		int ans = a;
		for(int i=2;i<=2*b;i++) ans = ans<sum[i]?ans:sum[i];
		printf("%d\n",ans);
	}
}