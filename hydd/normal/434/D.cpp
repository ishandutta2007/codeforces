#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int lim=2333333;
int n,m,s,t,maxflow,ans,vis[11000],dep[11000];
int a[11000],b[11000],c[11000],l[11000],r[11000],num[110][510];
int edgenum,F[1100000],V[1100000],Next[1100000],Head[11000],cur[11000];
void addedge(int u,int v,int f){
	V[++edgenum]=v; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f){
	addedge(u,v,f);
	addedge(v,u,0);
}
bool bfs(){
	for (int i=s;i<=t;i++) vis[i]=false,dep[i]=INF;
	dep[s]=0;
	vis[s]=true;
	queue<int> que;
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
inline int f(int i,int x){ return a[i]*x*x+b[i]*x+c[i];}
int main(){
	edgenum=1; memset(Head,0,sizeof(Head));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	int cnt=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		for (int j=l[i]-1;j<=r[i];j++) num[i][j+101]=++cnt;
		for (int j=l[i];j<=r[i];j++) Add(num[i][j+100],num[i][j+101],lim-f(i,j));
	}
	s=0; t=cnt+1;
	for (int i=1;i<=n;i++){
		Add(s,num[i][l[i]+100],INF);
		Add(num[i][r[i]+101],t,INF);
	}
	int u,v,d;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		for (int j=max(l[u],l[v]+d)-1;j<=min(r[u],r[v]+d);j++)
			Add(num[u][j+101],num[v][j-d+101],INF);
	}
	printf("%d\n",lim*n-dinic());
	return 0;
}