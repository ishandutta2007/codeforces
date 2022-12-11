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

const double eps=1e-12;
const double Pi=acos(-1);

struct point {
	double x,y;
	point(double _x=0,double _y=0){ x=_x; y=_y;}
	inline double len(){ return sqrt(x*x+y*y);}
};
point S;ll m;

inline point operator -(point a,point b){ return point(a.x-b.x,a.y-b.y);} 

struct line {
	double k,b;
	line(double _k=0,double _b=0){ k=_k; b=_b;}
};
line a[maxn];
double angle[maxn];

inline point Intersection(line a,line b)
{
	double x=(a.b-b.b)/(b.k-a.k),y=a.k*x+a.b;
	return point(x,y);
}

line p[maxn];

int n;

inline void init()
{
	n=read();
	S.x=read(); S.y=read(); m=read();
	S.x/=1000; S.y/=1000;
	REP(i,1,n)
	{
		double k=read(),b=read();
		k/=1000; b/=1000;
		a[i]=line(k,b);
		angle[i]=atan(a[i].k);
		if(k*S.x+b>S.y)angle[i]+=Pi*0.5;
		else angle[i]-=Pi*0.5;
	}
}

inline double Dis(line a,point S)
{
	return fabs(a.k*S.x-S.y+a.b)/sqrt(a.k*a.k+1);
}

struct pdd {
	double fi,se;
	int id;
};

inline bool operator < (pdd a,pdd b){ return a.fi<b.fi;}

//#define pdd pair<double,double>

pdd b[maxn];
double sx[maxn];
int num,tx;
int s[maxn];

inline void Add(int x){ for(;x<=tx;x+=x&(-x))s[x]++;}
inline int Sum(int x){ int res=0;for(;x;x-=x&(-x))res+=s[x];return res; }

inline void Check(double &x)
{
	while(x<-Pi)x+=2*Pi;
	while(x>Pi)x-=2*Pi;
}

inline ll check(double R)
{
	num=0; tx=0;
	REP(i,1,n)
	{
		double t=Dis(a[i],S);
		if(t>=R)continue;
		double jd=acos(t/R);
		++num;
		b[num].fi=angle[i]-jd; b[num].se=angle[i]+jd; b[num].id=i;
		Check(b[num].fi); Check(b[num].se);
		if(b[num].fi>b[num].se)swap(b[num].fi,b[num].se);
		sx[++tx]=b[num].fi; sx[++tx]=b[num].se;
	}
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-sx-1;
	REP(i,1,num)b[i].fi=lower_bound(sx+1,sx+tx+1,b[i].fi)-sx,b[i].se=lower_bound(sx+1,sx+tx+1,b[i].se)-sx;
	sort(b+1,b+num+1);
	memset(s,0,sizeof(int)*(tx+1));
	ll ans=0;
	REP(i,1,num)
	{
		ans+=Sum(b[i].se)-Sum(b[i].fi);
		Add(b[i].se);
	}
	return ans;
}

struct node {
	int pos;int id;
};
inline bool operator < (node a,node b){ return a.pos==b.pos?a.id<b.id:a.pos<b.pos;}

double ans;int NUM;

inline double Calc(int i,int j)
{
	point t=Intersection(a[i],a[j]);
	return (t-S).len();
}

inline void Find(double R)
{
	num=0; tx=0;
	REP(i,1,n)
	{
		double t=Dis(a[i],S);
		if(t>=R)continue;
		double jd=acos(t/R);
		++num;
		b[num].fi=angle[i]-jd; b[num].se=angle[i]+jd; b[num].id=i;
		Check(b[num].fi); Check(b[num].se);
		if(b[num].fi>b[num].se)swap(b[num].fi,b[num].se);
		sx[++tx]=b[num].fi; sx[++tx]=b[num].se;
	}
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-sx-1;
	REP(i,1,num)b[i].fi=lower_bound(sx+1,sx+tx+1,b[i].fi)-sx,b[i].se=lower_bound(sx+1,sx+tx+1,b[i].se)-sx;
	sort(b+1,b+num+1);

	set<node>s;
	REP(i,1,num)
	{
		set<node>::iterator it;
		it=s.lower_bound((node){b[i].fi,0});
		for(;it!=s.end() && it->pos<b[i].se;it++)
		{
			ans+=Calc(b[i].id,it->id);
			NUM++;
		}
		s.insert((node){b[i].se,b[i].id});
//Add(b[i].se);
	}
}

inline void doing()
{
	double l=0,r=1e10;
	REP(th,1,100)
	{
		double mid=(l+r)*0.5;
		if(check(mid)>=m)r=mid;
		else l=mid;
	}
	Find(l);
	printf("%.10lf\n",ans+l*(m-NUM));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF607E.in","r",stdin);
	freopen("CF607E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}