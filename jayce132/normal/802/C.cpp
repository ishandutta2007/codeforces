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

const int maxn=200;
const int inf=0x3f3f3f3f;

struct node {
	int v,next,w,cost;
};
node e[maxn*maxn*4];
int cnt=1,start[maxn];

inline void addedge(int u,int v,int w,int cost){ e[++cnt]=(node){v,start[u],w,cost};start[u]=cnt;}
inline void Addedge(int u,int v,int w,int cost){ addedge(u,v,w,cost);addedge(v,u,0,-cost);}

int n,k,a[maxn],c[maxn],S,T,tot;
int num[maxn][2];
int ST;

inline void init()
{
	n=read();k=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,n)c[i]=read();
	S=++tot; T=++tot; ST=++tot; Addedge(S,ST,k,0);
	REP(i,1,n)
	{
		num[i][0]=++tot,num[i][1]=++tot;
		Addedge(num[i][0],num[i][1],1,-inf);
		Addedge(num[i][1],T,1,0);
	}
	REP(i,0,n-1)REP(j,i+1,n)
	{
		Addedge(i?num[i][1]:ST,num[j][0],1,i && a[i]==a[j]?0:c[a[j]]);
	}
}

ll dist[maxn];
int pre[maxn],vis[maxn];

inline ll min_cost(int S,int T)
{
	queue<int>q;
	ll ans=0;
	while(1)
	{
		REP(i,1,tot)dist[i]=1ll<<60,pre[i]=vis[i]=0;
		q.push(S); dist[S]=0;
		while(!q.empty())
		{
			int u=q.front();q.pop(); vis[u]=0;
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
		if(dist[T]==(1ll<<60))break;
		if(dist[T]>=0)break;
		int flow=inf;
		for(int i=pre[T];i;i=pre[e[i^1].v])chkmin(flow,e[i].w);//,cerr<<e[i].v<<" ";
		for(int i=pre[T];i;i=pre[e[i^1].v])e[i].w-=flow,e[i^1].w+=flow;
		ans+=1ll*flow*dist[T];
	}
	return ans;
}

inline void doing()
{
	printf("%lld\n",min_cost(S,T)+1ll*n*inf);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("lib.in","r",stdin);
	freopen("lib.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}