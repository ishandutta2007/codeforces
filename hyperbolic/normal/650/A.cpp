#include <stdio.h>
#include <algorithm>
struct str{
	int x0;
	int y0;
}x[200010];
bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	if(a.y0==b.y0) return a.x0<b.x0;
	return a.y0<b.y0;
}
int main()
{
	int a,b,c,i;
	long long int sum1=0,sum2=0,s;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d%d",&b,&c);
		x[i].x0 = b;
		x[i].y0 = c;
	}
	std::sort(x+1,x+a+1,cmp);
	for(i=2,s=0;i<=a;i++)
	{
		if(x[i-1].x0==x[i].x0) s++;
		else
		{
			sum1 += s * (s+1) / 2;
			s = 0;
		}
	}
	sum1 += s * (s+1) / 2;
	for(i=2,s=0;i<=a;i++)
	{
		if(x[i-1].x0==x[i].x0&&x[i-1].y0==x[i].y0) s++;
		else
		{
			sum2 += s * (s+1) / 2;
			s=0;
		}
	}
	sum2 += s * (s+1) / 2;
	std::sort(x+1,x+a+1,cmp2);
	for(i=2,s=0;i<=a;i++)
	{
		if(x[i-1].y0==x[i].y0) s++;
		else
		{
			sum1 += s * (s+1) / 2;
			s=0;
		}
	}
	sum1 += s * (s+1) / 2;
	printf("%I64d",sum1-sum2);
}