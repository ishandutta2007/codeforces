#include<cstdio>

double chk(double ax,double ay,double bx,double by,double cx,double cy)
{
	return ax*by+bx*cy+cx*ay-ay*bx-by*cx-cy*ax;
}

int main()
{
	int i,n,r=0;
	double sx,sy,ex,ey;
	double a,b,c,t1,t2;
	scanf("%lf%lf%lf%lf",&sx,&sy,&ex,&ey);
    scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a==0)
		{
            c/=-b;
			r+=((c-sy)*(c-ey)<0);
		}
		else if(b==0)
		{
			c/=-a;
			r+=((c-sx)*(c-ex)<0);
		}
		else
		{
			t1=(a*1e6+c)/-b;
            t2=(-a*1e6+c)/-b;
            r+=(chk(1e6,t1,-1e6,t2,sx,sy)*chk(1e6,t1,-1e6,t2,ex,ey)<0);
		}
	}
	printf("%d",r);
}