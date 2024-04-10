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

const int maxn=1e4+20;
const int inf=0x3f3f3f3f;

struct node {
	int v,next,w,cost;
};
node e[maxn<<1];
int cnt=1,start[maxn];
inline void addedge(int u,int v,int w,int cost){ e[++cnt]=(node){v,start[u],w,cost};start[u]=cnt;}
inline void Addedge(int u,int v,int w,int cost){ addedge(u,v,w,cost);addedge(v,u,0,-cost);}

int n,m;
int ry[maxn];
int ans;
int Sn,Tn,tot;

inline void init()
{
	n=read();m=read();
	REP(i,1,m)
	{
		int u=read(),v=read(),c=read(),f=read();
		if(f<=c)
		{
			ry[u]-=f; ry[v]+=f;
			Addedge(v,u,f,1);
			Addedge(u,v,c-f,1);
			Addedge(u,v,inf,2);
		}else
		{
			ans+=f-c;
			ry[u]-=c; ry[v]+=c;
			Addedge(v,u,c,1);
			Addedge(u,v,f-c,0);
			Addedge(u,v,inf,2);
		}
	}
	tot=n;
	Addedge(n,1,inf,0);
	Sn=++tot; Tn=++tot;
	REP(i,1,n)
		if(ry[i]>0)Addedge(Sn,i,ry[i],0);
		else Addedge(i,Tn,-ry[i],0);
}

int dist[maxn],pre[maxn],vis[maxn];

queue<int>q;

inline int cost_flow(int S,int T)
{
	int ans=0;
	while(1)
	{
		REP(i,1,tot)dist[i]=inf,pre[i]=vis[i];
		q.push(S);dist[S]=0;
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
					if(!vis[v])q.push(v),vis[v]=1;
				}
			}
		}
		if(dist[T]==inf)break;
		int flow=inf;
		for(int i=pre[T];i;i=pre[e[i^1].v])chkmin(flow,e[i].w);
		for(int i=pre[T];i;i=pre[e[i^1].v])e[i].w-=flow,e[i^1].w+=flow;
		ans+=dist[T]*flow;
	}
	return ans;
}

inline void doing()
{
	printf("%d\n",cost_flow(Sn,Tn)+ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("ff.in","r",stdin);
	freopen("ff.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}