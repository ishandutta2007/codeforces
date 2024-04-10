#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
int n,m;
const int INF=0X3f3f3f3f;
const int N=5009;
const int M=50009;
struct P{int to,ne,flow,cap,cost;};
int g[59][59],du[59];
int pp=0;
pii p[2509];
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
		for(int u=n+1;u<=pp;++u){
			int x=0;
			for(int i=head[u];i;i=e[i].ne){
				if(e[i].flow==1){
					x=e[i].to;
				}
			}
			g[x][p[u].fi^p[u].se^x]=1;
		}
		return make_pair(ans,sum);
	}
}d;

int main(){
	cin>>n>>m;
	pp=n;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[u][v]=1;
		du[u]++;
	}
	d.s=N-3;
	d.t=N-6;
	for(int i=1;i<=n;++i){
		for(int j=du[i];j<n-1;++j)d.add(i,d.t,1,j);
		for(int j=i+1;j<=n;++j){
			if(g[i][j]==0&&g[j][i]==0){
				p[++pp]=make_pair(i,j);
				d.add(d.s,pp,1,0);
				d.add(pp,i,1,0);
				d.add(pp,j,1,0);
			}
		}
	}
	d.get();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<g[i][j];
		}
		cout<<"\n";
	}
	return 0;
}