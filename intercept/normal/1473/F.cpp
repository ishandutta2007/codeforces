#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const ll INF=1ll<<50;
const int N=3009;
const int M=100009;
int n;
int a[M],w[M],vis[M];
struct Dinic{
	struct P{int to,ne;ll flow,cap;}e[M];
	int head[N],dis[N],cur[N];
	int s,t,num=1;
	queue<int>q;
	bool vis[N];
	bool bfs(){
		memset(vis,0,sizeof(vis));
		q.push(t);dis[t]=0;vis[t]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=head[u];i;i=e[i].ne){
				int v=e[i].to;
				if(!vis[v]&&e[i^1].cap>e[i^1].flow){
					dis[v]=dis[u]+1;
					q.push(v),vis[v]=1;
				}
			}
		}
		return vis[s];
	}
	ll dfs(int u,ll a){
		if(u==t||a==0)return a;
		ll flow=0,f;
		for(int&i=cur[u];i;i=e[i].ne){
			int v=e[i].to;
			if(dis[v]==dis[u]-1){
				f=dfs(v,min(a,e[i].cap-e[i].flow));
				e[i].flow+=f; e[i^1].flow-=f;
				a-=f;         flow+=f;
				if(a==0)break;
			}
		}
		return flow;
	}
	void add(int u,int v,ll w){
		e[++num]=(P){v,head[u],0,w};head[u]=num;
		e[++num]=(P){u,head[v],0,0};head[v]=num;
	}
	ll maxflow(){
		ll ans=0;
		while(bfs()){
			memcpy(cur,head,sizeof(head));
			ans+=dfs(s,INF);
		}
		return ans;
	}
}d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	d.s=n+1;
	d.t=n+2;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		cin>>w[i];
		if(w[i]>0)d.add(d.s,i,w[i]),ans+=w[i];
		else d.add(i,d.t,-w[i]);
		for(int j=1;j<=a[i];++j){
			if(a[i]%j==0&&vis[j]){
				d.add(i,vis[j],INF);
			}
		}
		vis[a[i]]=i;
	}
	//cout<<d.maxflow()<<"\n";
	cout<<ans-d.maxflow()<<"\n";
	return 0;
}
/*
1 1
1

*/