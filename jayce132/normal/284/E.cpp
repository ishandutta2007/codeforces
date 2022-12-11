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
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;

int n,q,t;
ll now;
int fa[maxn],to[maxn];
int a[maxn];
int f[maxn],vis[maxn];

inline void init()
{
	n=read();q=read();t=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,q)
	{
		int x=read(),y=read();
		to[x]=y; fa[y]=x;
	}
	REP(i,1,n)if(!fa[i])
	{
		int x=i;
		while(to[x])
		{
			if(vis[x])puts("0"),exit(0);
			vis[x]=1;
			now+=a[x];
			a[to[x]]+=a[x];
			x=to[x];
		}
		vis[x]=1;
	}
	REP(i,1,n)if(!vis[i])puts("0"),exit(0);
}

const int mod=1e9+7;

inline void pls(int &a,int b)
{
	a+=b; a-=a>=mod?mod:0;
}

inline void doing()
{
	f[0]=1;
	REP(j,1,n)
	{
		for(int i=a[j];i<=t-now;i++)pls(f[i],f[i-a[j]]);
	}
	if(now<=t)printf("%d\n",f[t-now]);
	else puts("0");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("283c.in","r",stdin);
	freopen("283c.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}