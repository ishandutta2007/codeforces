#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int l = 1, r = 0;
		long long int ans = 0;
		for(int i=a;i>=1;i--)
		{
			
			while(l<=a && x[l]+x[i]<b) l++;
			while(r+1<=a && x[r+1]+x[i]<=c) r++;
			if(l<i)
			{
				int t = i-1<r?i-1:r;
				ans += (t-l+1);
			}
		}
		printf("%lld\n",ans);
	}
}