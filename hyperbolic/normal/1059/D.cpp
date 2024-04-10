#include <stdio.h>
#include <vector>
#include <math.h>

int a;
double MAX = 1;
std::pair<double,double> P[100010];
bool func(double h)
{
	
	double left = -MAX, right = MAX;
	for(int i=1;i<=a;i++)
	{
		if(2*h<P[i].second) return false;
		double limit = sqrt(2*h-P[i].second);
		limit *= sqrt(P[i].second);
		if(right<P[i].first-limit) return false;
		if(P[i].first+limit<left) return false;
		
		right = right<P[i].first+limit?right:P[i].first+limit;
		left = left>P[i].first-limit?left:P[i].first-limit;
	}
	return true;
}

int main()
{
	for(int i=1;i<=20;i++) MAX *= 10;
	scanf("%d",&a);
	
	int isPlus = 0, isMinus = 0;
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i]=std::make_pair(b,c);
		if(c>0) isPlus = 1;
		if(c<0) isMinus = 1;
	}
	if(isPlus==1&&isMinus==1)
	{
		printf("-1");
		return 0;
	}
	if(isMinus==1) for(int i=1;i<=a;i++) P[i].second*=(-1);
	
	double min = 0, max = MAX;
	double ans = MAX;
	
	int count = 150;
	while(count--)
	{
		double h = (min+max)/2;
		if(func(h))
		{
			ans = h;
			max = h;
		}
		else min = h;
	}
	printf("%.12lf",ans);
}