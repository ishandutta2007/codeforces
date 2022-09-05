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

const int N=50+5;
int sgn(const double &x,const double &eps=1e-9)
{
	return x<-eps?-1:x>eps;
}
double sqr(const double &x)
{
	return x*x;
}
struct Point
{
	double x,y;
	Point unit()
	{
		double len=sqrt(sqr(x)+sqr(y));
		assert(sgn(len));
		return {x/len,y/len};
	}
}p[N];
int n;
Point operator -(const Point &a,const Point &b)
{
	return {a.x-b.x,a.y-b.y};
}
Point operator +(const Point &a,const Point &b)
{
	return {a.x+b.x,a.y+b.y};
}
Point operator *(const Point &a,const double &b)
{
	return {a.x*b,a.y*b};
}
double dis(const Point &a,const Point &b)
{
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
double sum_len[N];
pair<double,double> mx[N][N];//v,f(v)

double F(int i,int j,double vi)
{
	Point p0=p[i]+(p[i+1]-p[i]).unit()*vi;
	double l;Point d;
	if(j<i)
	{
		l=sum_len[i]-sum_len[j+1]+vi;
		d=(p[j]-p[j+1]).unit();
		p0=p[j+1]-p0;
	}
	else 
	{
		l=sum_len[j]-sum_len[i]-vi;
		d=(p[j+1]-p[j]).unit();
		p0=p[j]-p0;
	}
	double len=dis(p[j],p[j+1]);
	auto F=[&](const double &v)->double
	{
		double mu=sqr(d.x*v+p0.x)+sqr(d.y*v+p0.y);
		if(sgn(mu)<=0)return 1;
		return (v+l)/sqrt(mu);
	};
	double ans=max(F(0),F(len));
	Point p3=p0-d*l;
	double a=sqr(p3.x)+sqr(p3.y),b=d.x*p3.x+d.y*p3.y;
	//v'=-b/a,v=-a/b-l
	if(sgn(b))
	{
		double v=-a/b-l;
		if(sgn(v)>0&&sgn(len-v)>0)chmax(ans,F(v));
	}
	return ans;
}
void init_mx(int i,int j)
{
	double l=0,r=dis(p[i],p[i+1]);
	rep(tmp,1,200)
	{
		double m1=(l*2+r)/3,m2=(l+2*r)/3;
		if(F(i,j,m1)>F(i,j,m2))r=m2;
		else l=m1;
	}
	mx[i][j].first=l;
	mx[i][j].second=F(i,j,l);
	//printf("%d %d %f %f\n",i,j,mx[i][j].first,mx[i][j].second);
}

pair<double,double> check(const double &v,int i,int j)
{
	if(mx[i][j].second<v)return {1,0};
	pair<double,double>ans;
	double l=0,r=mx[i][j].first;
	rep(tmp,0,50)
	{
		double mid=(l+r)/2;
		if(F(i,j,mid)>=v)r=mid;
		else l=mid;
	}
	ans.first=l;
	l=mx[i][j].first;r=dis(p[i],p[i+1]);
	rep(tmp,0,50)
	{
		double mid=(l+r)/2;
		if(F(i,j,mid)>=v)l=mid;
		else r=mid;
	}
	ans.second=l;
	return ans;
}
bool check(const double &v)
{
	rep(i,1,n)
	{
		vector<pair<double,double>>seg;
		rep(j,1,i-1)seg.push_back(check(v,i,j));
		rep(j,i+1,n)
		{
			auto p1=check(v,i,j);
			for(auto p0:seg)
			if(max(p0.first,p1.first)<min(p0.second,p1.second))return 1;
		}
	}
	return 0;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n+1){p[i].x=read();p[i].y=read();}
	rep(i,1,n)sum_len[i+1]=sum_len[i]+dis(p[i],p[i+1]);
	rep(i,1,n)
	rep(j,1,n)
	if(j!=i)init_mx(i,j);
	double l=1,r=2000;
	rep(tmp,1,50)
	{
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.9f\n",l);
}