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
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;
const int inf=0x3f3f3f3f;

struct node {
	int v,next,w;
};
node e[maxn<<2];
int cnt=1,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}
inline void Addedge(int u,int v,int w){ addedge(u,v,w);addedge(v,u,0);}

int col[maxn],n,m,g,v[maxn];
int S,T,tot;
int ans;
int rk[maxn];

inline void init()
{
	n=read();m=read();g=read();
	tot=n+m;S=++tot; T=++tot;
	REP(i,1,n)col[i]=read();
	REP(i,1,n)v[i]=read();
	REP(i,1,n)
	{
		if(col[i]==0)Addedge(S,i,v[i]);
		else Addedge(i,T,v[i]);
	}
	REP(i,1,m)
	{
		int sex=read();
		int w=read(),k=read();
		ans+=w;
		REP(j,1,k)rk[j]=read();
		w+=read()*g;
		if(sex==1)
		{
			Addedge(n+i,T,w);
			REP(j,1,k)Addedge(rk[j],i+n,inf);
		}else
		{
			Addedge(S,i+n,w);
			REP(j,1,k)Addedge(i+n,rk[j],inf);
		}
	}
}

int cur[maxn],lev[maxn];

inline bool bfs()
{
	static queue<int>q;
	while(!q.empty())q.pop();
	REP(i,1,tot)lev[i]=0;
	lev[S]=1; q.push(S);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		EREP(i,u)
		{
			int v=e[i].v;
			if(e[i].w && !lev[v])
			{
				lev[v]=lev[u]+1;
				if(v==T)return 1;
				q.push(v);
			}
		}
	}
	return 0;
}

int dfs(int u,int flow)
{
	if(u==T)return flow;
	int tag=0;
	for(int &i=cur[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(lev[v]==lev[u]+1 && e[i].w)
		{
			int c=dfs(v,min(flow-tag,e[i].w));
			if(c)
			{
				e[i].w-=c;
				e[i^1].w+=c;
				tag+=c;
				if(tag==flow)return tag;
			}
		}
	}
	return tag;
}

inline void doing()
{
	while(bfs())
	{
		REP(i,1,tot)cur[i]=start[i];
		ans-=dfs(S,inf);
	}
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("biologist.in","r",stdin);
	freopen("biologist.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}