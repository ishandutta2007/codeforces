#include <stdio.h>

int x[1000010];
double ans[1000010];
void func(int s, int t)
{
	if(s>t) return;
	if(s==t)
	{
		ans[s] = x[s];
		return;
	}
	
	int h = (s+t)/2;
	func(s,h), func(h+1,t);
	int p1 = h, p2 = h;
	double sum = ans[h];
	while(p2<t)
	{
		p2++;
		if(sum/(p2-p1)<ans[p2])
		{
			for(int i=p1;i<p2;i++) ans[i] = sum/(p2-p1);
			return;
		}
		else
		{
			sum += ans[p2];
			while(p1-1>=s)
			{
				if(sum/(p2-p1+1) < ans[p1-1]) sum += ans[--p1];
				else break;
			}
		}
	}
	for(int i=p1;i<=p2;i++) ans[i] = sum/(p2-p1+1);
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	func(1,a);
	for(int i=1;i<=a;i++) printf("%.12lf\n",ans[i]);
}