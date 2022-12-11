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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=2e5+20;
#define pii pair<int,int>

int n;
pii p[maxn];
ll T;
int sx[maxn],tx;
int P[maxn];

struct point {
	double x,y;
	point(double _x=0,double _y=0){ x=_x; y=_y;}
};
point a[maxn],b[maxn];

inline point operator -(point a,point b){ return point(a.x-b.x,a.y-b.y);}
inline double cross(point a,point b){ return b.x*a.y-a.x*b.y;}

struct node {
	vector<point>Convex;
};
node c[(1<<19)+20];
#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

inline void init()
{
	n=read();
	REP(i,1,n)p[i].fi=read();
	REP(i,1,n)p[i].se=read(),T+=p[i].se;
	sort(p+1,p+n+1,[](pii a,pii b){ return (ll)a.se*b.fi==(ll)a.fi*b.se?a.fi<b.fi:(ll)a.se*b.fi<(ll)a.fi*b.se;});
	double pre=0;
	int j=0;
	REP(i,1,n)
	{
		while(j<i-1 && (ll)p[j+1].se*p[i].fi!=(ll)p[j+1].fi*p[i].se)
			pre+=p[++j].se;
		b[i]=point(pre+p[i].se,p[i].fi);
	}
			
	j=1; pre=0;
	REP(i,1,n)
	{
		while(j<=n && (ll)p[j].se*p[i].fi==(ll)p[j].fi*p[i].se)
			pre+=p[j++].se;
		a[i]=point(pre,p[i].fi);
	}



	REP(i,1,n)sx[++tx]=p[i].fi;
	REP(i,1,n)a[i].x=a[i].x*a[i].y,b[i].x=b[i].x*b[i].y;
	//sort(a+1,a+n+1,[](point a,point b){ return a.x<b.x;});
	
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-sx-1;
	REP(i,1,n)P[i]=lower_bound(sx+1,sx+tx+1,(int)a[i].y)-sx;
}

inline double Slope(point a,point b){ return (a.y-b.y)/(a.x-b.x);}

inline void Insert(vector<point>&Convex,point d)
{
	while(SZ(Convex)>1 && cross(*(Convex.end()-2)-Convex.back(),d-Convex.back())>=0)Convex.pop_back();
	Convex.push_back(d);
}

void insert(int x,point d,int o,int l,int r)
{
	Insert(c[o].Convex,d);
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)insert(x,d,left);
	else insert(x,d,right);
}

double C;

inline void Ask(vector<point>&Convex,point d)
{
	if(Convex.empty())return;
	int l=0,r=SZ(Convex)-1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(Slope(Convex[mid],d)<Slope(Convex[mid+1],d))r=mid;
		else l=mid+1;
	}
	chkmin(C,Slope(Convex[l],d));
}

void ask(int x,point d,int o,int l,int r)
{
	if(x<l)return;
	if(x>=r)
	{
		Ask(c[o].Convex,d);
		return;
	}
	int mid=l+r>>1;
	ask(x,d,left);
	if(x>mid)ask(x,d,right);
}

inline void doing()
{
	C=1e9;
	REP(i,1,n)
	{
		ask(P[i]-1,a[i],1,1,tx);
		insert(P[i],b[i],1,1,tx);
	}
	C=C*T;
	chkmin(C,1.);
	printf("%.10lf\n",C);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF639E.in","r",stdin);
	freopen("CF639E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}