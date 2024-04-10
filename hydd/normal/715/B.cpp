#include<cstdio>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
priority_queue<pii> que;
int n,m,L,s,t,u[11000],v[11000],cost[11000];
int edgenum=1,vet[21000],Next[21000],Head[11000];
ll val[21000],dis[21000],dis2[21000];
bool vis[11000];
void addedge(int u,int v,int cost){
    vet[++edgenum]=v; val[edgenum]=cost;
    Next[edgenum]=Head[u]; Head[u]=edgenum;
}
void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[s]=0; que.push(pii(0,s));
    int u,v;
    while (!que.empty()){
        u=que.top().second;
        que.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int e=Head[u];e;e=Next[e]){
            v=vet[e];
            if (vis[v]) continue;
            if (dis[v]>dis[u]+val[e]){
                dis[v]=dis[u]+val[e];
                que.push(pii(-dis[v],v));
            }
        }
    }
}
void dijkstra2(int s){
    memset(dis2,0x3f,sizeof(dis2));
    memset(vis,false,sizeof(vis));
    dis2[s]=0; que.push(pii(0,s));
    int u,v;
    while (!que.empty()){
        u=que.top().second;
        que.pop();
//        printf("%d\n",u);
        if (vis[u]) continue;
        vis[u]=true;
        for (int e=Head[u];e;e=Next[e]){
            v=vet[e];
            if (vis[v]) continue;
			if (!cost[e>>1]) val[e]=val[e^1]=max(1ll,L-dis[v]-dis2[u]);
            if (dis2[v]>dis2[u]+val[e]){
                dis2[v]=dis2[u]+val[e];
                que.push(pii(-dis2[v],v));
            }
        }
    }
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&cost[i]);
		if (!cost[i]) addedge(u[i],v[i],1),addedge(v[i],u[i],1);
		else addedge(u[i],v[i],cost[i]),addedge(v[i],u[i],cost[i]);
	}
	/*dijkstra(s);
	if (dis[t]>L){ puts("NO"); return 0;}
	edgenum=1; memset(Head,0,sizeof(Head));
	for (int i=1;i<=m;i++)
		addedge(u[i],v[i],cost[i]),addedge(v[i],u[i],cost[i]);*/
	dijkstra(t);
	dijkstra2(s);
	if (dis2[t]!=L){
		puts("NO");
		return 0;
	} else{
		puts("YES");
		for (int i=1;i<=m;i++) printf("%d %d %lld\n",u[i],v[i],val[i<<1]);
	}
	return 0;
}