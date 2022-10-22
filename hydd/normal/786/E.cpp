#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n,m,g,s,t,a[510000],vis[510000],dep[510000],Log2[510000],cnt,maxflow;
int edgenum=1,F[2100000],V[2100000],Next[2100000],Head[510000],cur[510000];
vector<pii> vec[21000];
void addedge(int u,int v,int f){
	V[++edgenum]=v; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f){
//	cerr<<u<<' '<<v<<' '<<f<<endl;
	addedge(u,v,f);
	addedge(v,u,0);
}
queue<int> que;
bool bfs(){
	for (int i=0;i<=cnt;i++) vis[i]=false,dep[i]=INF;
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
		for (int i=0;i<=cnt;i++) cur[i]=Head[i];
		while (dfs(s,INF));
	}
	return maxflow;
}
int fa[20][21000],pos[20][21000];
int jump(int u,int d){
	for (int i=18;i>=0;i--)
		if (d&(1<<i)) u=fa[i][u];
	return u;
}
void dfsd(int u,int f){
	dep[u]=dep[f]+1; fa[0][u]=f;
	for (int i=1;i<=18;i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
		if (fa[i][u]){
			pos[i][u]=++cnt;
			Add(pos[i][u],pos[i-1][u],INF); Add(pos[i][u],pos[i-1][fa[i-1][u]],INF);
		}
	}
	for (pii v:vec[u]){
		if (v.first==f) continue;
		pos[0][v.first]=v.second; dfsd(v.first,u);
	}
}
int LCA(int u,int v){
	if (dep[u]<dep[v]) swap(u,v);
	u=jump(u,dep[u]-dep[v]);
	if (u==v) return u;
	for (int i=18;i>=0;i--)
		if (fa[i][u]!=fa[i][v]){
			u=fa[i][u];
			v=fa[i][v];
		}
	return fa[0][u];
}
int main(){
	scanf("%d%d",&n,&m); Log2[0]=-1;
	for (int i=1;i<=n;i++) Log2[i]=Log2[i>>1]+1;
	s=0; t=n+m; int u,v;
	for (int i=1;i<=m;i++) Add(s,i,1);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v); Add(i+m,t,1);
		vec[u].push_back(pii(v,i+m)); vec[v].push_back(pii(u,i+m));
	}
	cnt=t; dfsd(1,0);
	int d,k;
	for (int i=1;i<=m;i++){
//		cerr<<cnt<<endl;
		scanf("%d%d",&u,&v); int w=LCA(u,v);
		if (u!=w){
			d=dep[u]-dep[w]; k=Log2[d];
			Add(i,pos[k][u],INF); Add(i,pos[k][jump(u,d-(1<<k))],INF); //assert(fa[k][jump(u,d-(1<<k))]==w);
		}
		if (v!=w){
			d=dep[v]-dep[w]; k=Log2[d];
			Add(i,pos[k][v],INF); Add(i,pos[k][jump(v,d-(1<<k))],INF); //assert(fa[k][jump(v,d-(1<<k))]==w);
		}
	}
	printf("%d\n",dinic());
	
	int cnt=0;
	for (int i=1;i<=m;i++)
		if (dep[i]==INF) cnt++;
	printf("%d",cnt);
	for (int i=1;i<=m;i++)
		if (dep[i]==INF) printf(" %d",i);
		
	cnt=0;
	for (int i=1;i<n;i++)
		if (dep[i+m]!=INF) cnt++;
	printf("\n%d",cnt);
	for (int i=1;i<n;i++)
		if (dep[i+m]!=INF) printf(" %d",i);
	return 0;
}