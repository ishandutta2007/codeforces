#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

typedef unsigned long long ull;

long long v[4000];
const long long INF=1e9;

namespace MaxF
{
	struct ed
	{
		int to,nxt;long long val;
	}ed[2000000];int head[500000],cur[500000],top=1;
	void add_edge(int u,int v,long long val)
	{
		top++;ed[top].to=v,ed[top].val=val,ed[top].nxt=head[u];head[u]=top;
	}
	void add_pair(int u,int v,long long val){add_edge(u,v,val),add_edge(v,u,0);}
	int n,s,t;int dis[500000];
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
				if(dis[v]==-1&&ed[i].val>0)
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
		for(int &i=cur[u];i&&flow>rlow;i=ed[i].nxt)
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
	void Dinic()
	{
		long long sum=0,tmp=0;
		while(bfs())
		{
			for(int i=0;i<=n;i++)cur[i]=head[i];
			while(tmp=dfs(s,INF))sum+=tmp;
		}
	}
	void init(int nn,int ss,int tt){n=nn,s=ss,t=tt,top=1;for(int i=0;i<=n;i++)head[i]=0;}
}

int id[3000];long long ans[3000];
vector<int> ed[3000];
void Solve(vector<int> V,long long l,long long r)
{
	if(l==r){for(int i=0;i<V.size();i++)ans[V[i]]=l;return;}
	if(!V.size())return;
	for(int i=0;i<V.size();i++)id[V[i]]=i+1;
	MaxF::init(V.size()+1,0,V.size()+1);
	for(int i=0;i<V.size();i++)
	{
		int u=V[i];
		for(int j=0;j<ed[u].size();j++)
		{
			int v=ed[u][j];if(!id[v])continue;MaxF::add_pair(i+1,id[v],INF);
		}
	}
	long long mid=(l+r)>>1;
	for(int i=0;i<V.size();i++)
	{
		int u=V[i];
		long long x=abs(mid-v[u])-abs(mid-v[u]+1);
		if(x>=0)MaxF::add_pair(0,i+1,x);else MaxF::add_pair(i+1,V.size()+1,-x);
	}
	MaxF::Dinic();
	vector<int> L,R;
	for(int i=0;i<V.size();i++){if(MaxF::dis[i+1]!=-1)R.push_back(V[i]);else L.push_back(V[i]);}
    for(int i=0;i<V.size();i++)id[V[i]]=0;
	Solve(L,l,mid);Solve(R,mid+1,r);
}

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=m;i++)
	{
		int u=0,v=0;scanf("%d%d",&u,&v);ed[u].push_back(v);
	}
	vector<int> V;for(int i=1;i<=n;i++)V.push_back(i);Solve(V,1,INF);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}