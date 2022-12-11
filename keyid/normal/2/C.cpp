#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const double EPS=1e-6;

struct Point
{
	double x,y;

	Point(){}
	Point(double x,double y):x(x),y(y){}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	Point operator + (const Point &b) const
	{
		return Point(x+b.x,y+b.y);
	}

	Point operator * (const double &z) const
	{
		return Point(x*z,y*z);
	}

	double operator * (const Point &b) const
	{
		return x*b.y-y*b.x;
	}

	double operator % (const Point &b) const
	{
		return x*b.x+y*b.y;
	}

	Point rot90() const
	{
		return Point(-y,x);
	}

	double len() const
	{
		return sqrt(x*x+y*y);
	}

	double lensqr() const
	{
		return x*x+y*y;
	}
};

struct line
{
	Point a,b;
};

struct Circle
{
	Point o;
	double r;

	void read()
	{
		scanf("%lf%lf%lf",&o.x,&o.y,&r);
	}
};

vector <Point> ans;

double xmul(const Point &a,const Point &b,const Point &c)
{
	return (b-a)*(c-a);
}

void solve(Circle c1,Circle c2,int &tp,line &r1,Circle &r2)
{
	if (c1.r==c2.r)
	{
		tp=1;
		r1.a=(c1.o+c2.o)*0.5;
		r1.b=r1.a+(c2.o-c1.o).rot90();
	}
	else
	{
		tp=2;
		Point a=c1.o+(c2.o-c1.o)*((double)c1.r/(c1.r+c2.r)),b=c1.o+(c2.o-c1.o)*((double)c1.r/(c1.r-c2.r));
		r2.o=(a+b)*0.5;
		r2.r=(a-r2.o).len();
	}
}

void solve_ls(const line &l1,const line &l2)
{
	double u=xmul(l1.a,l1.b,l2.a),v=xmul(l1.b,l1.a,l2.b);
	Point t;
	t.x=(l2.a.x*v+l2.b.x*u)/(u+v);
	t.y=(l2.a.y*v+l2.b.y*u)/(u+v);
	ans.pb(t);
}

void solve_cs(const Circle &cir1,const Circle &cir2)
{
	double x=(cir1.o-cir2.o).lensqr(),y=((cir1.r*cir1.r-cir2.r*cir2.r)/x+1)/2;
	double d=cir1.r*cir1.r/x-y*y;
	if (d<-EPS)
		return;
	if (d<0)
		d=0;
	Point q1=cir1.o+(cir2.o-cir1.o)*y;
	Point q2=((cir2.o-cir1.o)*sqrt(d)).rot90();
	ans.pb(q1-q2);
	ans.pb(q1+q2);
}

void solve_lc(const line &l,const Circle &cir)
{
	double x=(l.a-cir.o)%(l.b-l.a);
	double y=(l.b-l.a).lensqr();
	double d=x*x-y*((l.a-cir.o).lensqr()-cir.r*cir.r);
	if (d<-EPS)
		return;
	if (d<0)
		d=0;
	Point q1=l.a-((l.b-l.a)*(x/y));
	Point q2=(l.b-l.a)*(sqrt(d)/y);
	ans.pb(q1-q2);
	ans.pb(q1+q2);
}

int main()
{
	//freopen("read.txt","r",stdin);
	Circle c[3];
	for (int i=0;i<3;i++)
		c[i].read();
	int ret_tp[2];
	line ret_l[2];
	Circle ret_c[2];
	for (int i=1;i<3;i++)
		solve(c[0],c[i],ret_tp[i-1],ret_l[i-1],ret_c[i-1]);
	if (ret_tp[0]==1)
		if (ret_tp[1]==1)
			solve_ls(ret_l[0],ret_l[1]);
		else
			solve_lc(ret_l[0],ret_c[1]);
	else
		if (ret_tp[1]==1)
			solve_lc(ret_l[1],ret_c[0]);
		else
			solve_cs(ret_c[0],ret_c[1]);
	if (!ans.empty())
	{
		Point d=ans.front();
		for (int i=1;i<ans.size();i++)
			if ((d-c[0].o).len()>(ans[i]-c[0].o).len())
				d=ans[i];
		printf("%.7f %.7f\n",d.x,d.y);
	}
	return 0;
}