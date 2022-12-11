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

const int maxn=320;
const int inf=0x3f3f3f3f;
#define pii pair<int,int>

int n;
pii a[maxn];
int sx[maxn],tx;
int f[maxn][maxn],L[maxn];
int fL[maxn][maxn];
unordered_map<int,int>mp;

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int x=read(),l=read();
		a[i]=mkr(x,l);
		sx[++tx]=x;
		sx[++tx]=x-l;
		sx[++tx]=x+l;
	}
	sort(sx+1,sx+tx+1); sx[++tx]=inf;tx=unique(sx+1,sx+tx+1)-sx-1; REP(i,1,tx)mp[sx[i]]=i;
	sort(a+1,a+n+1);
	memset(f,inf,sizeof(f)); memset(fL,inf,sizeof(fL));
	REP(l,1,n)
	{
		f[l][l]=a[l].fi-a[l].se;
		REP(r,l+1,n)
		{
			f[l][r]=min(f[l][r-1],a[r].fi-a[r].se);
		}
	}
	REP(i,1,n)
	{
		L[i]=a[i].fi-a[i].se;
		DREP(j,i-1,1)if(a[j].fi>=L[i])chkmin(L[i],L[j]);
	}

	REP(l,1,n)
	{
		fL[l][l]=L[l];
		REP(r,l+1,n)
		{
			fL[l][r]=min(fL[l][r-1],L[r]);
		}
	}
}

int g[maxn];

inline void doing()
{
	memset(g,0,sizeof(g));
	DREP(i,tx,1)
	{
		chkmax(g[i],g[i+1]);
		int First=0;
		DREP(j,n,1)if(a[j].fi<sx[i])
		{
			if(!First)First=j;
			int Right=a[j].fi+a[j].se;
			int Left=min(a[j].fi,f[j+1][First]),wz=lower_bound(a+1,a+n+1,mkr(Left,0))-a;
			chkmin(Left,fL[wz][j-1]);
			chkmin(Right,sx[i]);
			chkmax(g[mp[Left]],g[i]+Right-Left);
		}
		{
			int j=First;
			int Right=a[j].fi;
			int Left=L[j];
			chkmin(Right,sx[i]);
			chkmax(g[mp[Left]],g[i]+Right-Left);
		
		}
		
	}
	int ans=0;
	REP(i,1,tx)chkmax(ans,g[i]);
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("559e.in","r",stdin);
	freopen("559e.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}