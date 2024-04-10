#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)

int cmp(const double &x,const double &eps=1e-7)
{
	return x<-eps?-1:x>eps;
}

const int N=1e5+5;
struct Point
{
	double x,y;
};
Point operator -(const Point &p1,const Point &p2)
{
	return {p1.x-p2.x,p1.y-p2.y};
}
Point p[N];double t[N];
int n;double w,h,e1,e2;

double x_of_y(const Point &p1,const Point &p2,const double &y)
{
	Point d=p2-p1;
	return p1.x+d.x/d.y*(y-p1.y);
}
Point p0,p1;double l;
double fix(double x)
{
	double x0=x_of_y(p0,{x,h},p1.y);
	if(cmp(abs(x0-p1.x)-l)<=0)return x;
	return x_of_y(p0,{p1.x+l*((x0<p1.x)?-1:1),p1.y},h);
}
bool ok(const double &speed)
{
//	if(speed<3&&speed>1)
//		int yyx=1;
	double xl=e2,xr=e2;
	p[0]={x_of_y({e1,0},{e2,h},1),1};
	rep(i,1,n)
	{
		p0=p[i-1];p1=p[i];
		l=speed*(t[i]-t[i-1]);
		if(!cmp(p1.y-p0.y)&&cmp(abs(p1.x-p0.x)-l)>0)return 0;
		double nl=max(0.0,x_of_y(p1,{w,0},h)),nr=min(w,x_of_y(p1,{0,0},h));
		double xl1=fix(xl);
		if(cmp(xl1-xl)<0)return 0;
		xl=xl1;
		double xr1=fix(xr);
		if(cmp(xr1-xr)>0)return 0;
		xr=xr1;
		if(cmp(xl-xr)>0)return 0;
		xl=max(nl,max(xl-l,x_of_y({x_of_y(p0,{xl,h},0)+l,0},p1,h)));
		xr=min(nr,min(xr+l,x_of_y({x_of_y(p0,{xr,h},0)-l,0},p1,h)));
		if(cmp(xl-xr)>0)return 0;
	}
	return 1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n>>w>>h>>e1>>e2;
	rep(i,1,n)scanf("%lf%lf%lf",t+i,&p[i].x,&p[i].y);
	if(!ok(w+1)){puts("-1");exit(0);}
	double l=0,r=w+1;
	rep(tmp,1,30)
	{
		double mid=(l+r)/2;
		if(ok(mid))r=mid;
		else l=mid;
	}
	printf("%f\n",r);
}