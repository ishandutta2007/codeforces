#include <stdio.h>
#define MAX 123456789
int x[200010],check[200010],down[200010],up[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a+1;i++) down[i] = up[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) down[x[i]]++, up[x[i]]++;
		for(int i=1;i<=a;i++) down[i] += down[i-1];
		for(int i=a;i>=1;i--) up[i] += up[i+1];
		
		int ans2 = a, ans1 = 1;
		for(int L=1;L<=a;L++)
		{
			int min = L, max = a;
			int val = MAX;
			while(min<=max)
			{
				int h = (min+max)/2;
				int t = down[L-1] + up[h+1];
				if(a-t-t >= b)
				{
					val = h;
					max = h-1;
				}
				else min = h+1;
			}
			if(ans2 - ans1 > (val-L)) ans1 = L, ans2 = val;
		}
		
		printf("%d %d\n",ans1,ans2);
		
		for(int i=1;i<=a;i++)
		{
			if(ans1<=x[i]&&x[i]<=ans2) check[i] = 1;
			else check[i] = -1;
		}
		
		int s = 0;
		int start = 1;
		int p = 1;
		for(int i=1;i<b;i++)
		{
			while(1)
			{
				s += check[p];
				if(s==1)
				{
					printf("%d %d\n",start,p);
					s = 0;
					start = p+1;
					p++;
					break;
				}
				else p++;
			}
		}
		printf("%d %d\n",start,a);
	}
}