#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
priority_queue<pii> que;
int n,m,u,v;
int edgenum,vet[4100000],Next[4100000],Head[2100000];
ll dis[2100000],val[4100000],cost;
bool vis[2100000];
void addedge(int u,int v,ll cost){
    vet[++edgenum]=v; val[edgenum]=cost;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dijkstra(int s) {
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[s]=0; que.push(pii(0,s));
    int u,v;
    while (!que.empty()){
        u=que.top().second; que.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int e=Head[u];e;e=Next[e]){
            v=vet[e];
            if (!vis[v]&&dis[v]>dis[u]+val[e]){
                dis[v]=dis[u]+val[e];
                que.push(pii(-dis[v],v));
            }
        }
    }
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%lld",&u,&v,&cost);
		addedge(u,v,2*cost); addedge(v,u,2*cost);
	}
	for (int i=1;i<=n;i++){
		scanf("%lld",&cost);
		addedge(0,i,cost);
	}
	dijkstra(0);
	for (int i=1;i<n;i++) printf("%lld ",dis[i]);
	printf("%lld\n",dis[n]);
	return 0;
}