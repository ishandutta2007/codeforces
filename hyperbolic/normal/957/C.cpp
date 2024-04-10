#include <stdio.h>

int x[100010];

double ans;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	ans = -1;
	for(int i=2;i<a;i++)
	{
		int min = i+1, max = a;
		int p = i;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h]-x[i-1]<=b)
			{
				p = h;
				min = h+1;
			}
			else max = h-1;
		}
		if(p==i) continue;
		double val = (double)(x[p]-x[i])/(x[p]-x[i-1]);
		ans = ans>val?ans:val;
	}
	if(ans==-1) printf("-1");
	else printf("%.12lf",ans);
}