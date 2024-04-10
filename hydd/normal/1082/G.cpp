/*********************************************************************
 * Sourceysy
 * ProblemCF1082G
 * Authorhydd
 * Date2020/9/2
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,m,s,t; ll maxflow,sum;
int vis[31000];// 
int dep[31000];
int edgenum,F[810000],V[810000],Next[810000],Head[31000];
//f:floww: 
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
ll dinic(){
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
int main(){
	edgenum=1; memset(Head,0,sizeof(Head));
	scanf("%d%d",&n,&m);
	s=0; t=n+m+1; int x;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		Add(i,t,x);
	}
	int u,v,c;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c); sum+=c;
		Add(n+i,u,INF); Add(n+i,v,INF);
		Add(s,n+i,c);
	}
	printf("%lld\n",sum-dinic());
	return 0;
}