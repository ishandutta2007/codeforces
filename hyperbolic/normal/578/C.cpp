#include <stdio.h>
#define MIN -10000
#define MAX 10000
int x[200010];
double y[200010];
double Max(double a, double b)
{
	return a>b?a:b;
}
double Min(double a, double b)
{
	return a<b?a:b;
}
double abs(double a)
{
	return a>0?a:-a;
}
int main()
{
	int a,i,count=70;
	double min = MIN, max = MAX;
	double h,s1,s2;
	double ans1,ans2;
	scanf("%d",&a);
	for(i=1;i<=a;i++) scanf("%d",&x[i]);
	while(count--)
	{
		h = (min+max)/2;
		for(i=1;i<=a;i++) y[i] = x[i] - h;
		s1 = y[1] , s2 = y[1];
		ans1 = y[1], ans2 = y[1];
		for(i=2;i<=a;i++)
		{
			s1 = Max(s1+y[i],y[i]);
			s2 = Min(s2+y[i],y[i]);
			ans1 = Max(ans1,s1);
			ans2 = Min(ans2,s2);
		}
		if(abs(ans1)>abs(ans2)) min = h;
		else max = h;
	}
	for(i=1;i<=a;i++) y[i] = x[i] - h;
	s1 = y[1] , s2 = y[1];
	ans1 = y[1], ans2 = y[1];
	for(i=2;i<=a;i++)
	{
		s1 = Max(s1+y[i],y[i]);
		s2 = Min(s2+y[i],y[i]);
		ans1 = Max(ans1,s1);
		ans2 = Min(ans2,s2);
	}
	printf("%.12lf",Max(abs(ans1),abs(ans2)));
}