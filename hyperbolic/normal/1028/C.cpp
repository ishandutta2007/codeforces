#include <stdio.h>
#include <algorithm>
#define MAX 1234567890
struct str{
	int x1;
	int y1;
	int x2;
	int y2;
	int selected;
}x[150010];

bool cmp1(str a, str b)
{
	return a.x1<b.x1;
}
bool cmp2(str a, str b)
{
	return a.y1<b.y1;
}
bool cmp3(str a, str b)
{
	return a.x2<b.x2;
}
bool cmp4(str a, str b)
{
	return a.y2<b.y2;
}

int a;
bool func()
{
	int min1 = MAX, min2 = MAX, max1 = -MAX, max2 = -MAX;
	for(int i=1;i<=a;i++)
	{
		if(x[i].selected==0) continue;
		max1 = max1>x[i].x1?max1:x[i].x1;
		max2 = max2>x[i].y1?max2:x[i].y1;
		min1 = min1<x[i].x2?min1:x[i].x2;
		min2 = min2<x[i].y2?min2:x[i].y2;
	}
	if(max1<=min1&&max2<=min2)
	{
		printf("%d %d",max1,max2);
		return true;
	}
	return false;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		x[i]={b,c,d,e,1};
	}
	std::sort(x+1,x+a+1,cmp1);
	x[a].selected = 0;
	if(func()) return 0;
	x[a].selected = 1;
	
	std::sort(x+1,x+a+1,cmp2);
	x[a].selected = 0;
	if(func()) return 0;
	x[a].selected = 1;
	
	std::sort(x+1,x+a+1,cmp3);
	x[1].selected = 0;
	if(func()) return 0;
	x[1].selected = 1;
	
	std::sort(x+1,x+a+1,cmp4);
	x[1].selected = 0;
	if(func()) return 0;
	x[1].selected = 1;
}