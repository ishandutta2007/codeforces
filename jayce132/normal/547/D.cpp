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

const int maxn=4e5+20;
const int inf=0x3f3f3f3f;

struct Edge {
	int u,v;
};
Edge E[maxn];

struct node {
	int v,next,w;
};
node e[maxn<<3];
int cnt=1,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}
inline void Addedge(int u,int v,int w){ addedge(u,v,w);addedge(v,u,0);}

int n,m,S,T,Sn,Tn,tot;
int rdx[maxn],rdy[maxn],EX;
int dy[maxn];

inline void Add(int x,int y,int l,int r)
{
	dy[x]-=l; dy[y]+=l;
	Addedge(x,y,r-l);
}

inline void build()
{
	REP(i,1,tot)
		if(dy[i]>0)Addedge(Sn,i,dy[i]),EX+=dy[i];
		else if(dy[i]<0)Addedge(i,Tn,-dy[i]);
}

inline void init()
{
	n=2e5; m=read();
	tot=4e5; S=++tot; T=++tot; Sn=++tot; Tn=++tot;
	REP(i,1,m)
	{
		int x=read(),y=read();
		E[i]=(Edge){x,y};
		Addedge(x,y+n,1);
		rdx[x]++; rdy[y]++;
	}
	REP(i,1,n)if(rdx[i])
	{
		if(rdx[i]&1)Add(S,i,rdx[i]>>1,(rdx[i]>>1)+1);
		else Add(S,i,rdx[i]>>1,rdx[i]>>1);
	}
	
	REP(i,1,n)if(rdy[i])
	{
		if(rdy[i]&1)Add(i+n,T,rdy[i]>>1,(rdy[i]>>1)+1);
		else Add(i+n,T,rdy[i]>>1,rdy[i]>>1);
	}
	Addedge(T,S,inf);
	build();
}

int to[maxn];
int lev[maxn],cur[maxn];

inline int max_flow(int S,int T)
{
	function<bool()> bfs=[&]() {
		queue<int>q;
		memset(lev,0,sizeof(int)*(tot+1));
		q.push(S); lev[S]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			EREP(i,u)
			{
				int v=e[i].v;
				if(!lev[v] && e[i].w)
				{
					lev[v]=lev[u]+1;
					q.push(v);
					if(v==T)return 1;
				}
			}
		}
		return 0;
	};

	function<int(int ,int)> dfs=[&](int u,int flow) {
		if(u==T)return flow;
		int tag=0;
		for(int &i=cur[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(lev[v]==lev[u]+1 && e[i].w)
			{
				int c=dfs(v,min(e[i].w,flow-tag));
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
	};

	int ans=0;
	while(bfs())
	{
		memcpy(cur,start,sizeof(int)*(tot+1));
		ans+=dfs(S,inf);
	}
	return ans;
}

inline void doing()
{
	cerr<<max_flow(Sn,Tn)<<" "<<EX<<endl;
	REP(u,1,n)EREP(i,u)
	{
		int v=e[i].v;
		if(n<v && v<=n*2)to[i>>1]=e[i].w;
	}
	REP(i,1,m)if(to[i])putchar('b');
	else putchar('r');
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}