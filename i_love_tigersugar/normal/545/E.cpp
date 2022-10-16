 #include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
const long long INF=(long long)1e18+7LL;
struct Edge {
    int u,v,c;
    Edge() {
        u=v=c=0;
    }
    void input(void) {
        scanf("%d%d%d",&u,&v,&c);
    }
    int other(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
Edge edge[MAX];
vector<int> adj[MAX];
long long dist[MAX];
int m,n,root;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,m) {
        edge[i].input();
        adj[edge[i].u].push_back(i);
        adj[edge[i].v].push_back(i);
    }
    scanf("%d",&root);
}
void dijkstra(void) {
    memset(dist,0x3f,sizeof dist);
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
    dist[root]=0;
    q.push(make_pair(0,root));
    while (!q.empty()) {
        int u=q.top().se;
        long long w=q.top().fi;
        q.pop();
        if (w>dist[u]) continue;
        FORE(it,adj[u]) {
            int v=edge[*it].other(u);
            if (dist[v]>dist[u]+edge[*it].c) {
                dist[v]=dist[u]+edge[*it].c;
                q.push(make_pair(dist[v],v));
            }
        }
    }
}
void process(void) {
    vector<int> res;
    FOR(u,1,n) if (u!=root && dist[u]<INF) {
        int chs=-1;
        FORE(it,adj[u]) {
            int v=edge[*it].other(u);
            if (dist[u]==dist[v]+edge[*it].c) {
                if (chs<0 || edge[chs].c>edge[*it].c) chs=*it;
            }
        }
        assert(chs>0);
        res.push_back(chs);
    }
    sort(ALL(res));
    res.resize(unique(ALL(res))-res.begin());
    long long sum=0;
    FORE(it,res) sum+=edge[*it].c;
    cout<<sum<<"\n";
    FORE(it,res) printf("%d ",*it); printf("\n");
}
int main(void) {
    loadGraph();
    dijkstra();
    process();
    return 0;
}