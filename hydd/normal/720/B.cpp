/*********************************************************************
 * Source
 * Problem
 * Authorhydd
 * Date
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,s,t,cnt,maxflow;
int vis[51000];// 
int dep[51000];
int edgenum,F[1100000],V[1100000],Next[1100000],Head[51000];
//f:floww: 
void addedge(int u,int v,int f){
	V[++edgenum]=v; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f){
//	printf("%d %d %d\n",u,v,f);
	addedge(u,v,f);
	addedge(v,u,0);
}
bool bfs(){
	memset(vis,false,sizeof(vis));
	memset(dep,0x3f,sizeof(dep));
	dep[s]=0;
	vis[s]=true;
	queue<int> que;
	que.push(s);
	while (!que.empty()){
		int u=que.front(); que.pop();
		vis[u]=false;
		for (int e=Head[u];e;e=Next[e]){
			int d=V[e];
			if (dep[d]>dep[u]+1&&F[e]){
				dep[d]=dep[u]+1;
				if (!vis[d]){
					que.push(d);
					vis[d]=true;
				}
			}
		}
	}
	return dep[t]<INF;
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
		if ((!vis[d]||d==t)&&F[e]&&dep[d]==dep[u]+1){
			int minflow=dfs(d,min(flow-used,F[e]));
			if (minflow!=0) F[e]-=minflow,F[e^1]+=minflow,used+=minflow;
			if (used==flow) break;
		}
	}
	return used;
}
int dinic(){
	maxflow=0;
	while (bfs()){
		vis[t]=1;
		while (vis[t]){
			memset(vis,false,sizeof(vis));
			dfs(s,INF); 
		}
	}
	return maxflow;
}
namespace tmp{
	int edgenum=1,vet[81000],val[81000],Next[81000],Head[11000];
	bool vis[11000],inn[41000]; int dep[11000],fa[11000];
	int col[11000],num[11000];
	void addedge(int u,int v,int cost){
		vet[++edgenum]=v; val[edgenum]=cost;
		Next[edgenum]=Head[u]; Head[u]=edgenum;
	}
	void dfs(int u,int f){
		vis[u]=true; dep[u]=dep[f]+1; fa[u]=f;
		int v,c;
		for (int e=Head[u];e;e=Next[e]){
			v=vet[e]; c=val[e];
			if (v==f||inn[e>>1]) continue;
			if (vis[v]){
				cnt++; Add(s,cnt,dep[u]-dep[v]);
				for (int j=dep[v]+1;j<=dep[u];j++) inn[num[j]]=true,Add(cnt,col[j],1);
				inn[e>>1]=true; Add(cnt,c,1);
			} else{
				col[dep[u]+1]=c; num[dep[u]+1]=e>>1;
				dfs(v,u);
				if (!inn[e>>1]) Add(s,c,1);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m); int u,v,c,mx=0;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c); mx=max(mx,c);
		tmp::addedge(u,v,c); tmp::addedge(v,u,c);
	}
	cnt=mx;
	edgenum=1; memset(Head,0,sizeof(Head));
	s=0; t=50001; tmp::dfs(1,0);
	for (int i=1;i<=mx;i++) Add(i,t,1);
	printf("%d\n",dinic());
	return 0;
}