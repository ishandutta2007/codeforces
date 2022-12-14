#include <stdio.h>

int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) x[i]*=2, y[i]*=2;
		
		int ans = (int)1e9;
		int min = 0, max = (int)1e9;
		while(min<=max)
		{
			int h = (min+max)/2;
			int L = 0, R = (int)1e9;
			for(int i=1;i<=a;i++)
			{
				if(y[i]>h)
				{
					min = h+1;
					goto u;
				}
				int l = x[i]-(h-y[i]);
				int r = x[i]+(h-y[i]);
				L = L>l?L:l;
				R = R<r?R:r;
			}
			if(L<=R)
			{
				ans = L;
				max = h-1;
			}
			else min = h+1;
			u:;
		}
		
		if(ans%2==0) printf("%d\n",ans/2);
		else printf("%d.5\n",ans/2);
	}
}