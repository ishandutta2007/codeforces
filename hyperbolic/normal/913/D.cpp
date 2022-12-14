#include <stdio.h>
#include <algorithm>

struct str{
	int x0;
	int y0;
	int index;
}x[200010],y[200010];
bool cmp1(str a,str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	if(a.y0==b.y0) return a.x0<b.x0;
	return a.y0<b.y0;
}
int z[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].x0,&x[i].y0);
	for(int i=1;i<=a;i++) x[i].index = i;
	std::sort(x+1,x+a+1,cmp1);
	
	int min=0, max=a, ans=0;
	while(min<=max)
	{
		int h = (min+max)/2;
		int pivot = a+1;
		for(int i=1;i<=a;i++)
		{
			if(x[i].x0>=h)
			{
				pivot = i;
				break;
			}
		}
		if(a-pivot+1<h)
		{
			max = h-1;
			continue;
		}
		for(int i=pivot;i<=a;i++) y[i] = x[i];
		std::sort(y+pivot,y+a+1,cmp2);
		int sum = 0;
		for(int i=pivot;i<pivot+h;i++) sum+=y[i].y0;
		if(sum>b)
		{
			max = h-1;
			continue;
		}
		else
		{
			ans = h;
			for(int i=1;i<=h;i++) z[i] = y[pivot+i-1].index;
			min = h+1;
			continue;
		}
	}
	printf("%d\n%d\n",ans,ans);
	for(int i=1;i<=ans;i++) printf("%d ",z[i]);
}