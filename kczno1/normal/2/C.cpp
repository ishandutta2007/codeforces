#include<bits/stdc++.h>
using namespace std;

const double eps=1e-7;
int cmp(const double &x)
{
	return x<-eps?-1:x>eps;
}
struct circle
{
	double x,y,r;
	void re()
	{
		cin>>x>>y>>r;
	}
};
circle C1,C2,C3;
double sqr(const double &x)
{
	return x*x;
}
void get(circle C1,circle C2,double &a,double &bx,double &by,double &c)
{
	double k;
#define add(r,x,y,w) k=sqr(r)*w;a+=k;bx-=k*2*x;by-=k*2*y;c+=k*(sqr(x)+sqr(y)); 
	add(C2.r,C1.x,C1.y,1)
	add(C1.r,C2.x,C2.y,-1)
#undef add
	//bx/=a;by/=a;c/=a;
}
void jie(double a,double b,double c,double &x1,double &x2)
{
	if(!cmp(a))
	{
		x1=x2=-c/b;
		return ;
	}
	if(cmp(sqr(b)-4*a*c)<0)exit(0); 
	double s=-b/(2*a),d=sqrt(sqr(b)-4*a*c)/(2*a);
	x1=s+d;x2=s-d;
}
double dis1(double x,double y)
{
	return sqr(x-C1.x)+sqr(y-C1.y);
}

int main()
{
//	freopen("1.in","r",stdin);
	C1.re();C2.re();C3.re();
	double a1=0,a2=0,bx1=0,by1=0,c1=0,bx2=0,by2=0,c2=0;
	get(C1,C2,a1,bx1,by1,c1);
	get(C1,C3,a2,bx2,by2,c2);
	double a=a2*bx1-a1*bx2,b=a2*by1-a1*by2,c=a2*c1-a1*c2;
	if(!cmp(a1))
	{
		if(!cmp(a2))
		{
			#define jie(x1,y1,x2,y2) -(c1*y2-c2*y1)/(x1*y2-x2*y1)
			//#define mu(x1,y1,x2,y2) x1*y2-x2*y1
			//	printf("%.5lf %.5lf\n",mu(bx1,by1,bx2,by2),mu(by1,bx1,by2,bx2));
				printf("%.5lf %.5lf\n",jie(bx1,by1,bx2,by2),jie(by1,bx1,by2,bx2));
			#undef jie
			//#undef mu
			return 0;
		}
		a=bx1;b=by1;c=c1;
		swap(a1,a2);swap(bx1,bx2);swap(by1,by2);swap(c1,c2);	
	}
	bool swaped=0;
	if(!cmp(b)){swaped=1;swap(a,b);swap(bx1,by1);}
	a=-a/b;c=-c/b;
	double x1,x2;
	jie( a1*(1+sqr(a)),bx1+a1*2*a*c+by1*a,a1*sqr(c)+by1*c+c1 ,x1,x2);
	double y1=a*x1+c,y2=a*x2+c; 
	if(swaped){swap(x1,y1);swap(x2,y2);}
	if(dis1(x1,y1)>dis1(x2,y2)){swap(x1,x2);swap(y1,y2);}
	printf("%.5lf %.5lf\n",x1,y1);
}