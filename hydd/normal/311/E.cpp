#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,g,s,t,a[310000],vis[310000],dep[310000],maxflow;
int edgenum=1,F[610000],V[610000],Next[610000],Head[310000],cur[310000];
void addedge(int u,int v,int f){
	V[++edgenum]=v; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f){
	addedge(u,v,f);
	addedge(v,u,0);
}
queue<int> que;
bool bfs(){
	for (int i=s;i<=t;i++) vis[i]=false,dep[i]=INF;
	dep[s]=0; vis[s]=true;
	que.push(s);
	while (!que.empty()){
		int u=que.front(); que.pop();
		vis[u]=false;
		for (int e=Head[u];e;e=Next[e]){
			int v=V[e];
			if (dep[v]>dep[u]+1&&F[e]){
				dep[v]=dep[u]+1;
				if (!vis[v]){
					que.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return dep[t]!=INF;
}
int dfs(int u,int flow){
	if (u==t){ 
		maxflow+=flow;
		return flow;
	}
	int used=0;
	for (int &e=cur[u];e;e=Next[e]){
		int v=V[e];
		if (F[e]&&dep[v]==dep[u]+1){
			int minflow=dfs(v,min(flow-used,F[e]));
			F[e]-=minflow; F[e^1]+=minflow; used+=minflow;
			if (used==flow) break;
		}
	}
	return used;
}
int dinic(){
	maxflow=0;
	while (bfs()){
		for (int i=s;i<=t;i++) cur[i]=Head[i];
		while (dfs(s,INF));
	}
	return maxflow;
}
int main(){
	scanf("%d%d%d",&n,&m,&g);
	s=0; t=n+m+1; int v;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&v);
		if (!a[i]) Add(s,i,v);
		else Add(i,t,v);
	}
	int ans=0,x,u,k,tmp;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&v,&k); ans+=v;
		for (int j=1;j<=k;j++){
			scanf("%d",&u);
			if (!x) Add(n+i,u,INF);
			else Add(u,n+i,INF);
		}
		scanf("%d",&tmp);
		if (tmp) v+=g;
		if (!x) Add(s,n+i,v);
		else Add(n+i,t,v);
	}
	printf("%d\n",ans-dinic());
	return 0;
}