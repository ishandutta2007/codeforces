#include <stdio.h>
#define error 0.00001
int x[100010],y[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
	
	double S = 0, T = 0;
	for(int i=1;i<=a;i++) S+=x[i];
	for(int i=1;i<=a;i++) T+=y[i];
	if(S<=b)
	{
		printf("-1");
		return 0;
	}
	double min = 0, max = 2*(T/(S-b));
	double ans = 0;
	while(max-min>error)
	{
		double h = (min+max)/2;
		double s = 0;
		for(int i=1;i<=a;i++) if(h*x[i]>y[i]) s+=(h*x[i]-y[i])/b;
		if(s>h) max = h;
		else
		{
			ans = h;
			min = h;
		}
	}
	printf("%lf",ans);
}