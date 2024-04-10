#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
struct Edge {
    int u,v,t;
    Edge() {
        u=v=t=0;
    }
    Edge(int _u,int _v,int _t) {
        u=_u;v=_v;t=_t;
    }
    int otherNode(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
vector<int> adj[MAX];
Edge edge[MAX];
int dist[MAX],cost[MAX],trace[MAX];
bool used[MAX];
int n,m;
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,m) {
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        edge[i]=Edge(u,v,t);
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
}
void bfs(void) {
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    dist[1]=0;q.push(1);
    while (!q.empty()) {
        int u=q.front();q.pop();
        FORE(it,adj[u]) {
            int v=edge[*it].otherNode(u);
            if (dist[v]>=INF) {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}
void dijkstra(void) {
    memset(cost,0x3f,sizeof cost);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    cost[1]=0;q.push(make_pair(0,1));
    while (!q.empty()) {
        int w=q.top().fi;
        int u=q.top().se;
        q.pop();
        if (w!=cost[u]) continue;
        FORE(it,adj[u]) {
            int v=edge[*it].otherNode(u);
            if (dist[v]!=dist[u]+1) continue;
            if (cost[v]>cost[u]+(edge[*it].t==0)) {
                cost[v]=cost[u]+(edge[*it].t==0);
                trace[v]=*it;
                q.push(make_pair(cost[v],v));
            }
        }
    }
}
void process(void) {
    for (int u=n;u!=1;u=edge[trace[u]].otherNode(u)) used[trace[u]]=true;
    int cnt=0;
    FOR(i,1,m) {
        if (used[i] && edge[i].t==0) cnt++;
        if (!used[i] && edge[i].t==1) cnt++;
    }
    printf("%d\n",cnt);
    FOR(i,1,m) {
        if (used[i] && edge[i].t==0) printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].t^1);
        if (!used[i] && edge[i].t==1) printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].t^1);
    }
}
int main(void) {
    loadgraph();
    bfs();
    dijkstra();
    process();
    return 0;
}