#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		long long int ans = 0;
		for(int i=1;i<=a;i++) ans += (x[i]/b), x[i] %= b;
		std::sort(x+1,x+a+1);
		
		int min = 0, max = a/2;
		int ans2 = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			int start = a-2*h+1, end = a;
			int sum = 0;
			for(int i=start;i<=start+h-1;i++) if(x[i]+x[end+start-i]>=b) sum++;
			if(sum==h)
			{
				ans2 = h;
				min = h+1;
			}
			else max = h-1;
		}
		
		printf("%lld\n",ans+ans2);
	}
}