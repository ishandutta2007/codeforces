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

const int maxn=5e3+20;

struct Query {
	int x,y,len,dir;
};
Query qu[100020];

int n,q;

int a[maxn][maxn],b[maxn][maxn<<1],c[maxn][maxn<<1];
int s[maxn<<1];

inline void init()
{
	n=read(); q=read();
	REP(i,1,q)
	{
		int op=read();
		if(op==1)
		{
			int dir=read(),x=read(),y=read(),len=read();
			qu[i]=(Query){x,y,len,dir};
		}else
		{
			int x=read(),y=read();
			qu[i]=(Query){x,y,0,5};
		}
	}
}

int ans[100020];

inline void adds(int x0,int d){ for(int x=x0;x<=(n<<1);x+=x&(-x))s[x]+=d;}
inline void addxy(int x0,int y0,int d){ for(int x=x0,y;x<=n;x+=x&(-x))for(y=y0;y<=n;y+=y&(-y))a[x][y]+=d;}
inline void addxxy(int x0,int y0,int d){ for(int x=x0,y;x<=n;x+=x&(-x))for(y=y0;y<=(n<<1);y+=y&(-y))b[x][y]+=d;}
inline void addxyy(int x0,int y0,int d){ for(int x=x0,y;x<=n;x+=x&(-x))for(y=y0;y<=(n<<1);y+=y&(-y))c[x][y]+=d;}

inline int sums(int x0){ int res=0; for(int x=x0;x;x-=x&(-x))res+=s[x]; return res;}
inline int sumxy(int x0,int y0){ int res=0; for(int x=x0;x;x-=x&(-x))for(int y=y0;y;y-=y&(-y))res+=a[x][y]; return res;}
inline int sumxxy(int x0,int y0){ int res=0; for(int x=x0;x;x-=x&(-x))for(int y=y0;y;y-=y&(-y))res+=b[x][y]; return res;}
inline int sumxyy(int x0,int y0){ int res=0; for(int x=x0;x;x-=x&(-x))for(int y=y0;y;y-=y&(-y))res+=c[x][y]; return res;}

inline void add(int x,int y,int len,int d)
{
	adds(x+y-len,d);
	addxy(x+1,y+1,d);
	addxxy(x+1,x+y-len,-d);
	addxyy(y+1,x+y-len,-d);
}

inline int sum(int x,int y)
{
	return sums(x+y)+sumxy(x,y)+sumxxy(x,x+y)+sumxyy(y,x+y);
}

inline void work(int op)
{
	REP(i,1,q)
	{
		int x=qu[i].x,y=qu[i].y;
		if(op==1 || op==3)y=n-y+1;
		if(op<=2)x=n-x+1;
		if(qu[i].dir==5)
		{
			ans[i]+=sum(x,y);
			//if(i==5)cerr<<ans[i]<<endl;
		}
		else if(qu[i].dir==op)
		{
			add(x,y,qu[i].len,1);
		}
	}
	REP(i,1,q)
	{
		int x=qu[i].x,y=qu[i].y;
		if(op==1 || op==3)y=n-y+1;
		if(op<=2)x=n-x+1;
		if(qu[i].dir==op)
		{
			add(x,y,qu[i].len,-1);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	init();
	REP(i,1,4)work(i);
	REP(i,1,q)if(qu[i].dir>4)printf("%d\n",ans[i]);
	return 0;
}