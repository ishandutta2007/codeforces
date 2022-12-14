#include <stdio.h>
#include <algorithm>

struct str{
	int x0;
	int y0;
	int z0;
}x[110];
bool cmp(str a, str b)
{
	return a.x0<b.x0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d%d%d",&x[i].x0,&x[i].y0,&x[i].z0);
		std::sort(x+1,x+a+1,cmp);
		for(int i=a;i>=1;i--)
		{
			for(int j=i-1;j>=1;j--)
			{
				int L = x[i].y0-(x[i].x0-x[j].x0);
				int R = x[i].z0+(x[i].x0-x[j].x0);
				x[j].y0 = x[j].y0>L?x[j].y0:L;
				x[j].z0 = x[j].z0<R?x[j].z0:R;
				if(x[j].y0>x[j].z0)
				{
					printf("NO\n");
					goto u;
				}
			}
		}
		if(x[1].y0-x[1].x0<=b&&b<=x[1].z0+x[1].x0) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}