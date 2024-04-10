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

const int maxn=5e5+20;
const int mod=1e9+7;

inline void pls(ll &a,ll b){a+=b; a%=mod;}

struct point {
	ll x,y;
	point(ll _x=0,ll _y=0){ x=_x; y=_y;}
};

inline point operator -(point a,point b){ return point(a.x-b.x,a.y-b.y);}
inline ll cross(point a,point b){ return b.x*a.y-a.x*b.y;}

point p[maxn<<1];
int n;

ll Sum;

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int x=read(),y=read();
		p[i]=point(x,y);
	}
	REP(i,1,n)p[i+n]=p[i];
	REP(i,1,n)Sum+=cross(p[i],p[i+1]);
}

inline void doing()
{
	int j=1;
	ll ans=0;
	ll all=cross(p[1],p[2]),sum=cross(p[1],p[2]),sx=p[1].x,sy=p[1].y;
	REP(i,3,n*2)
	{
		pls(sx,p[i-1].x);
		pls(sy,p[i-1].y);
		sum+=cross(p[i-1],p[i]);
		pls(all,cross(p[i-1],p[i])%mod*(i-j));
		while(j<i-1 && ((unsigned ll)(sum+cross(p[i],p[j]))*2>Sum || (unsigned ll)(sum+cross(p[i],p[j]))*2==Sum && j>=n+1))
		{
			pls(all,-sum);
			sum-=cross(p[j],p[j+1]);
			pls(sx,-p[j].x);
			pls(sy,-p[j].y);
			j++;
		}
		if(i>=n+1)
		{
			pls(ans,all);
			pls(ans,-p[i].x*sy+p[i].y*sx);
		}
	}
	ans=((ll)n*(n-3)/2%mod*(Sum%mod)%mod-ans*2)%mod;
	ans=(ans+mod)%mod;
	printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}