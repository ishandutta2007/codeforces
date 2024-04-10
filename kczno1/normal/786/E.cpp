#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e4+5,L=15;
int n,m;
vector<int>lk[N];
int f[N][L],deep[N],dy[N][L];
pii e[N];

namespace FLOW
{
const int N=::N*L+1e4+5;
struct Edge
{
	int to,f,rev;
};
vector<Edge>lk[N];
void add_e(int x,int y,int f)
{
	lk[x].push_back({y,f,lk[y].size()});
	lk[y].push_back({x,0,lk[x].size()-1});
}
int n=2,S=1,T=2;
int g[N];
bool bfs()
{
	rep(i,1,n)g[i]=-1;
	g[S]=0;
	deque<int>q;
	q.push_back(S);
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		if(x==T)return 1;
		for(auto e:lk[x])
		if(e.f&&g[e.to]==-1)
		{
			g[e.to]=g[x]+1;
			q.push_back(e.to);
		}
	}
	return 0;
}
int nt[N];
int dfs(int x,int f)
{
	if(x==T)return f;
	int f0=f;
	for(int &i=nt[x];i<lk[x].size();++i)
	{
		auto &e=lk[x][i];
		if(!e.f||g[e.to]!=g[x]+1)continue;
		int del=dfs(e.to,min(e.f,f));
		f-=del;
		e.f-=del;lk[e.to][e.rev].f+=del;
		if(!f)break;
	}
	return f0-f;
}
void get_mf()
{
	int ans=0;
	while(bfs())
	{
		rep(i,1,n)nt[i]=0;
		ans+=dfs(S,N);
	}
	printf("%d\n",ans);
	
	static int q[N];
	rep(i,1,n)g[i]=-1;
	g[T]=0;
	int tail=1;
	q[1]=T;
	rep(head,1,tail)
	{
		int x=q[head];
		for(auto e:lk[x])
		if(lk[e.to][e.rev].f&&g[e.to]==-1)
		{
			g[e.to]=0;
			q[++tail]=e.to;
		}
	}
	vector<int>ans1;
	rep(i,1,m)
	if(g[n-(m-i)]!=-1)ans1.push_back(i);
	printf("%d\n",int(ans1.size()));
	for(auto i:ans1)printf("%d ",i);puts("");
	
	vector<int>ans2;
	rep(i,1,::n-1)
	{
		int x=e[i].first,y=e[i].second;
		if(y!=f[x][0])swap(x,y);
		if(g[dy[x][0]]==-1)ans2.push_back(i);
	}
	printf("%d\n",int(ans2.size()));
	for(auto i:ans2)printf("%d ",i);puts("");
}
};

void dfs(int x,int fr)
{
	deep[x]=deep[fr]+1;
	f[x][0]=fr;dy[x][0]=++FLOW::n;
	FLOW::add_e(dy[x][0],FLOW::T,1);
	rep(j,1,L-1)
	{
		f[x][j]=f[f[x][j-1]][j-1]; 
		dy[x][j]=++FLOW::n;
		FLOW::add_e(dy[x][j],dy[x][j-1],N);
		FLOW::add_e(dy[x][j],dy[f[x][j-1]][j-1],N);
	}
	for(auto y:lk[x])
	if(y!=fr)dfs(y,x);
}
int get_lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	per(j,L-1,0)
	if((deep[x]-deep[y])&(1<<j))x=f[x][j];
	if(x==y)return x;
	per(j,L-1,0)
	if(f[x][j]!=f[y][j]){x=f[x][j];y=f[y][j];}
	return f[x][0];
}
void add(int now,int x,int lca)
{
	int d=deep[x]-deep[lca];
	rep(j,0,L-1)
	if(d&(1<<j))
	{
		FLOW::add_e(now,dy[x][j],N);
		x=f[x][j];
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	cin>>n>>m;
	rep(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].push_back(y);
		lk[y].push_back(x);
		e[i]={x,y};
	}
	dfs(1,0);
	rep(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int lca=get_lca(x,y);
		int now=++FLOW::n;
		FLOW::add_e(FLOW::S,now,1);
		add(now,x,lca);
		add(now,y,lca);
	}
	FLOW::get_mf();
}