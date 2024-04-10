#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;

struct point {
	double x,y;
	double at;
	point(double _x=0,double _y=0){ x=_x;y=_y;}
	inline double len(){ return sqrt(x*x+y*y);}
};
point p[maxn<<3];

const double eps=1e-10;

inline double cross(point a,point b){ return b.x*a.y-a.x*b.y;}

inline point operator +(point a,point b){ return point(a.x+b.x,a.y+b.y);}
inline point operator -(point a,point b){ return point(a.x-b.x,a.y-b.y);}
inline point operator *(point a,double b){ return point(a.x*b,a.y*b);}
inline bool operator <(point a,point b){ return fabs(a.x-b.x)<eps?a.y<b.y:a.x<b.x;}
inline bool operator == (point a,point b){ return fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps;}

int ptot;

int n;

inline int Get_Convex(point *p,int n)
{
	static point q[maxn<<3]; int tail=1;
	point ST=p[1];
	REP(i,2,n)p[i]=p[i]-p[1],p[i].at=atan2(p[i].y,p[i].x);
	p[1]=point(0,0);
	sort(p+2,p+n+1,[](point a,point b){ return a.at==b.at?a.len()<b.len():a.at<b.at;});
	q[1]=p[1];
	REP(i,2,n)
	{
		while(tail>=2 && cross(p[i]-q[tail],q[tail-1]-q[tail])>=0)--tail;
		q[++tail]=p[i];
	}
	REP(i,1,tail)p[i]=q[i]+ST;
	return tail;
}

struct line {
 	point p,v;
};

inline line ZQX(point a,point b)
{
	point x=(a+b)*0.5,v=(b-a); line t;
	swap(v.x,v.y); v.y=-v.y;
	t.p=x; t.v=v;
	return t;
}

inline point Intersection(line a,line b)
{
	if(fabs(cross(a.v,b.v))<eps)return point(1e18,-1e18);
	double t=1.*cross(b.p-a.p,b.v)/cross(a.v,b.v);
	return a.p+a.v*t;
}

inline double Radius(point a,point b,point c)
{
	line l1=ZQX(a,b),l2=ZQX(b,c);
	point intersect=Intersection(l1,l2);
	if(intersect.x==1e18)return 0;
	return (a-intersect).len();
}

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int x=read(),y=read(),v=read();
		if(y+v<=1e5)p[++ptot]=point(x,y+v);
		else p[++ptot]=point(max(x-(y+v-1e5),0.),1e5),p[++ptot]=point(min(x+(y+v-1e5),1e5),1e5);
		
		if(y-v>=0)p[++ptot]=point(x,y-v);
		else p[++ptot]=point(max(x+(y-v),0),0),p[++ptot]=point(min(x-(y-v),(int)1e5),0);
		
		if(x-v>=0)p[++ptot]=point(x-v,y);
		else p[++ptot]=point(0,max(y+(x-v),0)),p[++ptot]=point(0,min(y-(x-v),(int)1e5));
		
		if(x+v<=1e5)p[++ptot]=point(x+v,y);
		else p[++ptot]=point(1e5,max(y-(x+v-1e5),0.)),p[++ptot]=point(1e5,min(y+(x+v-1e5),1e5));
	}
	sort(p+1,p+ptot+1);
	ptot=unique(p+1,p+ptot+1)-p-1;
	ptot=Get_Convex(p,ptot);
	p[ptot+1]=p[1]; p[ptot+2]=p[2];
}

inline void doing()
{
	double mx=0;int id=0;
	REP(i,1,ptot)
	{
		double R=Radius(p[i],p[i+1],p[i+2]);
		if(R>mx)mx=R,id=i;
	}
	/*if(n==99995)
	{
		printf("%d\n",ptot);
		REP(i,1,ptot)printf("%.0lf %.0lf\n",p[i].x,p[i].y);
		}*/
	
	REP(i,id,id+2)printf("%.0lf %.0lf\n",p[i].x,p[i].y);
	//cerr<<Radius(point(0,0),point(53985,0),point(91893,3))<<endl;

	//cerr<<Radius(point(94956,98918),point(96525,98885),point(98091,98852))<<endl;
}
/*
0 0

53985 0

91893 3
	94956 98918
	
96525 98885

98091 98852


*/

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF575E.in","r",stdin);
	freopen("CF575E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}