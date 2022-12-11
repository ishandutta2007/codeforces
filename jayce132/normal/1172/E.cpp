#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=4e5+20;


int col[maxn];

int n,fa[maxn],m;

vector<int>ed[maxn];

void dfs(int u){ for(int v:ed[u])if(v!=fa[u])fa[v]=u,dfs(v);}

struct event {
	int tim,u,d;
};

vector<event>now[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)col[i]=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		ed[u].push_back(v); ed[v].push_back(u);
	}
	dfs(1); fa[1]=n+1;
	REP(i,1,n)now[col[i]].push_back((event){0,i,0});
	REP(i,1,m)
	{
		int u=read(),x=read();
		now[col[u]].push_back((event){i,u,1});
		now[col[u]=x].push_back((event){i,u,0});
	}
	REP(i,1,n)now[col[i]].push_back((event){m+1,i,1});
}

ll ans[maxn];

struct node {
	int fa,ch[2];
	int sz,si;
    ll sz2,si2;
};
node c[maxn];

inline bool isroot(int x){ return c[c[x].fa].ch[0]!=x && c[c[x].fa].ch[1]!=x;}

#define lc (c[x].ch[0])
#define rc (c[x].ch[1])

inline void Merge(int x)
{
	c[x].sz=c[lc].sz+c[rc].sz+c[x].si;
	c[x].sz2=c[x].si2+1ll*c[lc].sz*c[lc].sz+1ll*c[rc].sz*c[rc].sz;
}

inline void rotate(int x)
{
	int y=c[x].fa,z=c[y].fa,k=c[y].ch[1]==x;
	if(!isroot(y))c[z].ch[c[z].ch[1]==y]=x; c[x].fa=z;
	c[y].ch[k]=c[x].ch[k^1]; c[c[y].ch[k]].fa=y;
	c[x].ch[k^1]=y; c[y].fa=x;
	Merge(y); Merge(x);
}

inline void splay(int x)
{
	while(!isroot(x))
	{
		int y=c[x].fa,z=c[y].fa;
		if(!isroot(y))
			(c[y].ch[1]==x)^(c[z].ch[1]==y)?rotate(x):rotate(y);
		rotate(x);
	}
}

inline void access(int x)
{
	for(int y=0;x;y=x,x=c[x].fa)
	{
		splay(x);
		if(rc)c[x].si+=c[rc].sz,c[x].si2+=1ll*c[rc].sz*c[rc].sz;
		rc=y;
		if(rc)c[x].si-=c[rc].sz,c[x].si2-=1ll*c[rc].sz*c[rc].sz;
		Merge(x);
	}
}

inline void link(int u,int fa){ access(fa);splay(fa);splay(u); c[u].fa=fa; c[fa].si+=c[u].sz; c[fa].si2+=1ll*c[u].sz*c[u].sz; Merge(fa);}
inline void cut(int u,int fa){ access(u); access(fa);splay(fa);splay(u); c[u].fa=0;  c[fa].si-=c[u].sz; c[fa].si2-=1ll*c[u].sz*c[u].sz; Merge(fa);}
inline int findroot(int x){ access(x); splay(x);while(lc)x=lc; splay(x); return x;} 

//0
//1

inline void doing()
{
	REP(i,1,n+1)c[i].sz=c[i].si=1,c[i].si2=c[i].sz2=0;

	REP(i,1,n)now[0].push_back((event){0,i,1});

	for(event x:now[0])
	{
		if(x.d==1)
		{
			int u=x.u,fau=findroot(fa[u]);
			link(u,fa[u]);
		}
	}
	
	REP(COL,1,n)
	{
		for(event x:now[COL])
		{
			if(x.d==1)
			{
				int u=x.u,fau=findroot(fa[u]);
				splay(u);   ans[x.tim]-=c[u].sz2;
				splay(fau); ans[x.tim]-=c[fau].sz2;
				link(u,fa[u]);
				splay(fau); ans[x.tim]+=c[fau].sz2;
			}else
			{
				int u=x.u,fau=findroot(fa[u]);
				splay(fau); ans[x.tim]-=c[fau].sz2;
				cut(u,fa[u]);
				splay(u); ans[x.tim]+=c[u].sz2;
				splay(fau); ans[x.tim]+=c[fau].sz2;
			}
		}
	}
	REP(i,1,m)ans[i]+=ans[i-1];
	REP(i,0,m)printf("%lld\n",-ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("odt.in","r",stdin);
	freopen("odt.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}