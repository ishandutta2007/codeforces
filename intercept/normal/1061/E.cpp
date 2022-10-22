#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int INF=0X3f3f3f3f;
const int N=1009;
const int M=2009;
struct P{int to,ne,flow,cap,cost;};
struct Dinic_cost{
	int s,t,num=1,head[N],dis[N];
	bool vis[N],in[N];
	P e[M<<1];
	bool spfa(){
		memset(dis,0X3f,sizeof(dis));
		queue<int>q;
		q.push(t);dis[t]=0;in[t]=1;
		while(!q.empty()){
			int u=q.front();q.pop();in[u]=0;
			for(int i=head[u];i;i=e[i].ne){
				int v=e[i].to;
				if(dis[v]>dis[u]+e[i^1].cost&&e[i^1].cap>e[i^1].flow){
					dis[v]=dis[u]+e[i^1].cost;
					if(!in[v]){q.push(v);in[v]=1;}
				}
			}
		}
		return dis[s]!=dis[0];
	}
	int dfs(int u,int a){
		if(u==t||a==0)return a;
		vis[u]=1;
		int flow=0,f;
		for(int i=head[u];i;i=e[i].ne){
			int v=e[i].to;
			if(!vis[v]&&dis[u]-e[i].cost==dis[v]&&e[i].cap>e[i].flow){
				f=dfs(v,min(a,e[i].cap-e[i].flow));
				flow+=f;
				a-=f;
				e[i].flow+=f;
				e[i^1].flow-=f;
				if(a==0)break;
			}
		}
		return flow;
	}
	void add(int u,int v,int cap,int cost){
		e[++num]=(P){v,head[u],0,cap,cost};head[u]=num;
		e[++num]=(P){u,head[v],0,0,-cost};head[v]=num;
	}
	pii get(){
		int ans=0,sum=0;
		while(spfa()){
			memset(vis,0,sizeof(vis));
			int flow=dfs(s,INF);
			ans+=flow;
			sum+=flow*dis[s];
		}
		return make_pair(ans,sum);
	}
}d;
int n,m,x,y,sz;
int a[N],p1[N],p2[N],siz[N],in[N][2];
vector<int>g1[N],g2[N];
void solve(int u,int fa,vector<int> *g,int *p,int o){
	in[u][o]=sz;
	for(auto v:g[u]){
		if(v!=fa&&!p[v]){
			solve(v,u,g,p,o);
		}
	}
}
int s[2];
void dfs(int u,int fa,vector<int> *g,int *p,int o){
	siz[u]=0;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u,g,p,o);
			siz[u]+=siz[v];
		}
	}
	if(p[u]){
		++sz;
		solve(u,fa,g,p,o);
		if(p[u]-siz[u]<0){
			cout<<"-1\n";
			exit(0);
		}
		if(o==0)d.add(d.s,sz,p[u]-siz[u],0);
		else d.add(sz,d.t,p[u]-siz[u],0);
		siz[u]=p[u];
	}
	if(fa==0)s[o]=siz[u];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x>>y;
	d.s=N-3;
	d.t=N-4;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g1[u].eb(v);
		g1[v].eb(u);
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g2[u].eb(v);
		g2[v].eb(u);
	}
	int q1,q2;
	cin>>q1;
	for(int i=1;i<=q1;++i){
		int k,x;
		cin>>k>>x;
		p1[k]=x;
	}
	cin>>q2;
	for(int i=1;i<=q2;++i){
		int k,x;
		cin>>k>>x;
		p2[k]=x;
	}
	dfs(x,0,g1,p1,0);
	dfs(y,0,g2,p2,1);
	for(int i=1;i<=n;++i){
		d.add(in[i][0],in[i][1],1,-a[i]);
	}
	auto o=d.get();
	if(s[0]==s[1]&&o.fi==s[0]){
		cout<<-o.se<<"\n";
	}
	else cout<<"-1\n";
	return 0;
}