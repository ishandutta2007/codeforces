#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,s,t,vis[11000],dep[11000],u[11000],v[11000],maxflow;
int edgenum,F[110000],V[110000],Next[110000],Head[11000],cur[11000];
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
bool check(int mid){
	s=0; t=n+m+1; edgenum=1;
	for (int i=s;i<=t;i++) Head[i]=0;
	for (int i=1;i<=m;i++){
		Add(u[i],n+i,1); Add(v[i],n+i,1);
		Add(n+i,t,1);
	}
	for (int i=1;i<=n;i++) Add(s,i,mid);
	return dinic()==m;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	int l=0,r=n;
	while (l<r){
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	check(l);
	for (int i=1;i<=m;i++){
		if (F[6*(i-1)+2]) printf("%d %d\n",v[i],u[i]);
		else printf("%d %d\n",u[i],v[i]);
	}
	return 0;
}