#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		long long int ans = 0;
		for(int i=1;i<a;i++)
		{
			if(x[i]!=x[i+1])
			{
				long long int s = i, t = (a-i);
				ans = ans>s*t?ans:s*t;
			}
		}
		if(ans==0) ans = a/2;
		printf("%lld\n",ans);
	}
}