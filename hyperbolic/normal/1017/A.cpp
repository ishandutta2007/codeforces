#include <stdio.h>
#include <algorithm>
struct str{
	int x0;
	int y0;
}x[1010];

bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0>b.x0;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		x[i].x0 = b+c+d+e;
		x[i].y0 = i;
	}
	std::sort(x+1,x+a+1,cmp);
	for(int i=1;i<=a;i++)
	{
		if(x[i].y0==1)
		{
			printf("%d",i);
			return 0;
		}
	}
}