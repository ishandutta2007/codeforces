#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}
 
const int maxn=5e5+20;
const int inf=0x3f3f3f3f;

struct node {
	int v,next,w,cost;
};
node e[maxn<<1];
int cnt=1,start[maxn];
inline void addedge(int u,int v,int w,int cost){ e[++cnt]=(node){v,start[u],w,cost};start[u]=cnt; }
inline void Addedge(int u,int v,int w,int cost){ addedge(u,v,w,cost);addedge(v,u,0,-cost);}

int n1,n2,m,r,b;
int tot;
char A[maxn];
char B[maxn];
int Swap;
int dy[maxn],EXFLOW;
int S,T,Sn,Tn;
int rd[maxn];

struct Edge {
	int u,v,ida,idb;
};
Edge E[maxn];

inline void Add(int u,int v,int l,int r)
{
	if(l>r)puts("-1"),exit(0);
	dy[v]+=l; dy[u]-=l;
	Addedge(u,v,r-l,0);
}

inline void build()
{
	REP(i,1,tot)
		if(dy[i]>0)Addedge(Sn,i,dy[i],0),EXFLOW+=dy[i];
		else if(dy[i]<0)Addedge(i,Tn,-dy[i],0);
}

inline void init()
{
	n1=read();n2=read();m=read();r=read();b=read();
	scanf("%s",A+1);
	scanf("%s",B+1);
	REP(i,1,n2)A[i+n1]=B[i];
	tot=n1+n2;S=++tot; T=++tot; Sn=++tot; Tn=++tot;
	 
	REP(i,1,m)
	{
		int u=read(),v=read()+n1;
		E[i]=(Edge){u,v};
		Addedge(u,v,1,b); E[i].ida=cnt-1;
		Addedge(v,u,1,r); E[i].idb=cnt-1;
		dy[v]++; dy[u]--;
		rd[u]++;rd[v]++;
	}
	REP(i,1,n1)
	{
		if(A[i]=='B')Add(S,i,rd[i]+1,rd[i]<<1);
		else if(A[i]=='U')Add(S,i,0,rd[i]<<1);
		//else if(A[i]=='U')
		//{
		//	if(rd[i]&1)puts("-1"),exit(0);
		//	else Add(S,i,rd[i]>>1,rd[i]>>1);
		//}
		else Add(S,i,0,rd[i]-1);
	}
	
	REP(i,n1+1,n1+n2)
	{
		if(A[i]=='B')Add(i,T,rd[i]+1,rd[i]<<1);
		else if(A[i]=='U')Add(i,T,0,rd[i]<<1);
			//{
			//if(rd[i]&1)puts("-1"),exit(0);
			//else Add(i,T,rd[i]>>1,rd[i]>>1);
			//}
		else Add(i,T,0,rd[i]-1);
	}
	Addedge(T,S,inf,0);
	build();
}

int dist[maxn],pre[maxn],vis[maxn];

inline void doing()
{
	int FLOW=0,ans=0;
	queue<int>q;
	while(1)
	{
		REP(i,1,tot)dist[i]=inf,pre[i]=vis[i]=0;
		q.push(Sn); dist[Sn]=0;
		while(!q.empty())
		{
			int u=q.front();q.pop();vis[u]=0;
			EREP(i,u)
			{
				int v=e[i].v;
				if(dist[v]>dist[u]+e[i].cost && e[i].w)
				{
					dist[v]=dist[u]+e[i].cost;
					pre[v]=i;
					if(!vis[v])vis[v]=1,q.push(v);
				}
			}
		}
		if(dist[Tn]==inf)break;
		int flow=inf;
		for(int i=pre[Tn];i;i=pre[e[i^1].v])chkmin(flow,e[i].w);
		for(int i=pre[Tn];i;i=pre[e[i^1].v])e[i].w-=flow,e[i^1].w+=flow;
		FLOW+=flow;
		ans+=flow*dist[Tn];
	}
	if(FLOW!=EXFLOW)puts("-1"),exit(0);
	printf("%d\n",ans);
	REP(i,1,m)
	{
		int u=E[i].u,v=E[i].v,a=0,b=0;
		a=e[E[i].ida].w;
		b=e[E[i].idb].w;
		if(!a)putchar('B');
		else if(!b)putchar('R');
		else putchar('U');
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1288f.in","r",stdin);
    freopen("1288f.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}