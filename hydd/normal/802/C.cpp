#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
int n,k,s,t,a[5100],c[5100],lst[5100];
int ans,maxflow;
int vis[5100];// 
int dist[5100]; 
int edgenum=1,F[310000],V[310000],Next[310000],W[310000],Head[5100];
//f:floww: 
void addedge(int u,int v,int f,int w){
	V[++edgenum]=v; W[edgenum]=w; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f,int w){
	addedge(u,v,f,w);
	addedge(v,u,0,-w);
}
bool spfa(){
	memset(vis,false,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	vis[s]=true;
	queue<int> que;
	que.push(s);
	while (!que.empty()){
		int u=que.front(); que.pop();
		vis[u]=false;
		for (int e=Head[u];e;e=Next[e]){
			int d=V[e];
			if (dist[d]>dist[u]+W[e]&&F[e]){
				dist[d]=dist[u]+W[e];
				if (!vis[d]){
					que.push(d);
					vis[d]=true;
				}
			}
		}
	}
	return dist[t]<INF;
}
int dfs(int u,int flow){
	if (u==t){ 
		vis[t]=true; maxflow+=flow;
		return flow;
	}
	int used=0;
	vis[u]=true;
	for (int e=Head[u];e;e=Next[e]){
		int d=V[e];
		if ((!vis[d]||d==t)&&F[e]&&dist[d]==dist[u]+W[e]){
			int minflow=dfs(d,min(flow-used,F[e]));
			if (minflow!=0) ans+=W[e]*minflow,F[e]-=minflow,F[e^1]+=minflow,used+=minflow;
			if (used==flow) break;
		}
	}
	return used;
}
int mincostmaxflow(){
	while (spfa()){
		vis[t]=1;
		while (vis[t]){
			memset(vis,false,sizeof(vis));
			dfs(s,INF); 
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	s=0; t=n*2+1;
	for (int i=1;i<=n;i++){
		Add(i,i+n,1,0);
		Add(i+n,t,1,0);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++){
		Add(s,i,1,c[a[i]]);
		if (lst[a[i]]) Add(i-1,lst[a[i]]+n,1,-c[a[i]]);
		lst[a[i]]=i;
	}
	for (int i=1;i<n;i++) Add(i,i+1,k-1,0);
	printf("%d\n",mincostmaxflow());
	return 0;
}