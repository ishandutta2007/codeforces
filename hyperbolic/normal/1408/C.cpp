#include <stdio.h>
#define MAX 1234567890
#define MIN -1234567890
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		x[a+1] = MAX;
		x[0] = MIN;
		double l0 = 0;
		double r0 = b;
		int vl = 1, vr = 1;
		int pl = 1, pr = a;
		double ans = 0;
		
		while(1)
		{
			double tl = (x[pl]-l0)/vl;
			double tr = (r0-x[pr])/vr;
			double tc = (r0-l0)/(vl+vr);
			double m = tl;
			m = m<tr?m:tr;
			m = m<tc?m:tc;
			if(m==tc)
			{
				printf("%.12lf\n",ans+m);
				break;
			}
			else
			{
				ans += m;
				if(m==tl&&m==tr)
				{
					r0 = x[pr];
					l0 = x[pl];
					vl++, vr++;
					pl++, pr--;
				}
				else if(m==tl)
				{
					r0 -= m*vr;
					l0 = x[pl];
					vl++;
					pl++;
				}
				else if(m==tr)
				{
					l0 += m*vl;
					r0 = x[pr];
					vr++;
					pr--;
				}
			}
		}
	}
}