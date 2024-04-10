#include<cstdio>
#include<queue>

using namespace std;

const long long INF=1e17;

long long val[200000];

namespace MCMF
{
	struct e
	{
		int to,nxt;long long val;
	}ed[200000];int used=1,head[20000],cur[20000];
	void add_edge(int u,int v,long long val)
	{
		used++;ed[used].to=v,ed[used].val=val,ed[used].nxt=head[u];head[u]=used;
	}
	void add_pair(int u,int v,long long val)
	{
		add_edge(u,v,val),add_edge(v,u,0);
	}
	int n,s,t;
	int dis[20000];
	bool bfs()
	{
		for(int i=0;i<=n;i++)dis[i]=-1;dis[s]=0;
		queue<int> q;q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=head[u];i;i=ed[i].nxt)
			{
				int v=ed[i].to;
				if(ed[i].val>0&&dis[v]==-1)
				{
					dis[v]=dis[u]+1;q.push(v);
				}
			}
		}
		return dis[t]!=-1;
	}
	long long dfs(int u,long long flow)
	{
		if(u==t)return flow;
		long long rlow=0;
		for(int &i=cur[u];i&&rlow<flow;i=ed[i].nxt)
		{
			int v=ed[i].to;
			if(dis[v]==dis[u]+1&&ed[i].val>0)
			{
				long long tmp=dfs(v,min(ed[i].val,flow-rlow));
				rlow+=tmp,ed[i].val-=tmp,ed[i^1].val+=tmp;
			}
		}
		return rlow;
	}
	long long Dinic()
	{
		long long sum=0,tmp=0;
		while(bfs())
		{
			for(int i=0;i<=n;i++)cur[i]=head[i];
			while((tmp=dfs(s,INF)))sum+=tmp;
		}
		return sum;
	}
	void init(int N,int S,int T){n=N,s=S,t=T;}
}

int main()
{
	int n=0,m=0,a=0,b=0;scanf("%d%d%d%d",&n,&m,&a,&b);int t=2*(n+m)+1;
	MCMF::init(t,0,t);
	for(int i=1,u=0,v=0,l=0;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&l);val[2*u-1]-=l,val[2*u]-=l,val[2*v-1]-=l,val[2*v]-=l,val[2*n+2*i-1]=val[2*n+2*i]=2*l;
		MCMF::add_pair(2*n+2*i-1,2*u-1,INF),MCMF::add_pair(2*n+2*i-1,2*v,INF);
		MCMF::add_pair(2*n+2*i,2*u,INF),MCMF::add_pair(2*n+2*i,2*v-1,INF);
	}
	val[2*a-1]+=INF/10,val[2*a]-=INF/10,val[2*b-1]-=INF/10,val[2*b]+=INF/10;
	long long sum=0;
	for(int i=1;i<=2*(n+m);i++)
	{
		if(val[i]>=0)MCMF::add_pair(0,i,val[i]),sum+=val[i];else MCMF::add_pair(i,t,-val[i]);
	}
	//puts("!!");
	long long flw=MCMF::Dinic();printf("%lld\n",-(sum-flw-INF/5));
	MCMF::bfs();
	for(int i=1;i<=n;i++)
	{
		if(MCMF::dis[2*i-1]!=-1&&MCMF::dis[2*i]==-1){putchar('A');}
		else if(MCMF::dis[2*i-1]==-1&&MCMF::dis[2*i]!=-1){putchar('B');}
		else putchar('C');
	}
}