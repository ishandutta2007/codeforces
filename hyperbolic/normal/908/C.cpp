#include <stdio.h>
#include <math.h>

int abs(int k)
{
	return k>0?k:-k;
}
int x[1010];
double y[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		y[i] = b;
		for(int j=1;j<i;j++)
		{
			if(abs(x[i]-x[j])<=2*b)
			{
				double c = y[j] + sqrt(4*b*b-(x[i]-x[j])*(x[i]-x[j]));
				y[i] = y[i]>c?y[i]:c;
			}
		}
	}
	for(int i=1;i<=a;i++) printf("%.12lf ",y[i]);
}