#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc
int sgn(const long double &x,const long double &eps=1e-12)
{
	return x<-eps?-1:x>eps;
}
long double sqr(const long double &x)
{
	return x*x;
}
struct Point
{
	long double x,y;
};
long double dis2(const Point &a,const Point &b)
{
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
Point operator -(const Point &a,const Point &b)
{
	return {a.x-b.x,a.y-b.y};
}
Point operator +(const Point &a,const Point &b)
{
	return {a.x+b.x,a.y+b.y};
}
long double operator ^(const Point &a,const Point &b)
{
	return a.x*b.x+a.y*b.y;
}
long double operator *(const Point &a,const Point &b)
{
	return a.x*b.y-b.x*a.y;
}
Point operator *(const Point &a,const long double &b)
{
	return {a.x*b,a.y*b};
}

Point O;long double r,r2;

struct Polygon
{
vector<Point>p;
int n;
long double area;
void init()
{
	n=read();
	p.resize(n+1);
	double px,py;
	rep(i,0,n-1)
	{
		scanf("%lf%lf",&px,&py);
		p[i]={px,py};
	}
	p[n]=p[0];
	area=0;
	rep(i,0,n-1)area+=p[i]*p[i+1];
	area=abs(area)/2;
}
bool point_in_polygon()
{
	int ret=0;
	rep(i,0,n-1)
	{
		Point u=p[i],v=p[i+1];
		if(sgn(u.y-v.y)<=0)swap(u,v);
		if(sgn(O.y-u.y)>0||sgn(O.y-v.y)<=0)continue;
		ret+=sgn((v-O)*(u-O))>0;
	}
	return ret&1;
}
bool has_intersection()
{
	rep(i,0,n-1)
	{
		if(sgn(dis2(p[i],O)-r2)<=0)return 1;
		if(sgn((O-p[i])^(p[i+1]-p[i]))>0 && sgn((O-p[i+1])^(p[i]-p[i+1]))>0)
			if(sgn(sqr((O-p[i])*(p[i+1]-p[i]))-r2*dis2(p[i],p[i+1]))<=0)return 1;
	}
	return point_in_polygon();
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	long double width,height;int n;
	cin>>width>>height>>n;
	vector<Polygon>poly(n);
	rep(i,0,n-1)poly[i].init();
	int q;
	cin>>q;
	rep(tmp,1,q)
	{
		double Ox,Oy,Or;
		scanf("%lf%lf%lf",&Ox,&Oy,&Or);
		O={Ox,Oy};r=Or;
		r2=sqr(r);
		long double area=0;
		vector<int>ans;
		rep(i,0,n-1)
		if(poly[i].has_intersection())
		{
			area+=poly[i].area;
			ans.push_back(i);
		}
		printf("%f %d",(double)area,int(ans.size()));
		for(auto x:ans)printf(" %d",x);
		puts("");
	}
}