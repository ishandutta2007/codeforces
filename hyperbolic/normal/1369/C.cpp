#include <stdio.h>
#include <algorithm>
int x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+b+1);
		int count = 0;
		for(int i=1;i<=b;i++) if(y[i]==1) count++;
		int p = 1;
		
		long long int ans = 0;
		for(int i=b;i>=1;i--)
		{
			if(y[i]>1)
			{
				ans += x[p];
				p += (y[i]-1);
			}
		}
		for(int i=a-b+1;i<=a;i++) ans += x[i];
		for(int i=a;i>=a-count+1;i--) ans += x[i];
		printf("%lld\n",ans);
	}
}