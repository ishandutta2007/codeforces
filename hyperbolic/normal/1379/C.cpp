#include <stdio.h>
#include <algorithm>

struct str{
	long long int x0;
	long long int y0;
}x[100010];
bool cmp(str a, str b)
{
	return a.x0>b.x0;
}
long long int y[100010],z[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			x[i]={c,d};
		}
		std::sort(x+1,x+b+1,cmp);
		for(int i=1;i<=b;i++) y[i] = x[i].x0;
		std::sort(y+1,y+b+1);
		for(int i=1;i<=b;i++) z[i] = z[i-1] + y[i];
		
		long long int ans = 0;
		for(int i=1;i<=b;i++)
		{
			int L = 1, R = b;
			int p = b+1;
			while(L<=R)
			{
				int h = (L+R)/2;
				if(y[h]>x[i].y0)
				{
					p = h;
					R = h-1;
				}
				else L = h+1;
			}
			if(x[i].x0>x[i].y0)
			{
				if(b-p+1<=a)
				{
					long long int S = z[b] - z[p-1] + (a-b+p-1)*x[i].y0;
					ans = ans>S?ans:S;
				}
				else
				{
					long long int S = z[b] - z[b-a];
					ans = ans>S?ans:S;
				}
			}
			else
			{
				if(b-p+1<a)
				{
					long long int S = z[b] - z[p-1] + (a-b+p-2)*x[i].y0 + x[i].x0;
					ans = ans>S?ans:S;
				}
				else
				{
					long long int S = z[b] - z[b-a+1] + x[i].x0;
					ans = ans>S?ans:S;
				}
			}
		}
		printf("%lld\n",ans);
	}
}