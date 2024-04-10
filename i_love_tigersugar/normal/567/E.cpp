#include<bits/stdc++.h>
#define MAX   200200
#define NMOD   2
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int mod[]={(int)1e9+2277,(int)1e9+5277,(int)1e9+8277,(int)1e9+9277};
const long long INF=(long long)1e18+7LL;
struct Hash {
    int val[NMOD];
    Hash() {
        memset(val,0,sizeof val);
    }
    Hash(int x) {
        REP(i,NMOD) val[i]=x;
    }
    void operator += (const Hash &x) {
        REP(i,NMOD) {
            val[i]+=x.val[i];
            if (val[i]>=mod[i]) val[i]-=mod[i];
        }
    }
    Hash operator * (const Hash &x) const {
        Hash res;
        REP(i,NMOD) res.val[i]=1LL*val[i]*x.val[i]%mod[i];
        return (res);
    }
    bool operator == (const Hash &x) const {
        REP(i,NMOD) if (val[i]!=x.val[i]) return (false);
        return (true);
    }
};
struct Edge {
    int u,v,c;
    Edge() {
        u=v=c=0;
    }
    Edge(int _u,int _v,int _c) {
        u=_u;v=_v;c=_c;
    }
    int other(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
Edge edge[MAX];
vector<int> adj[MAX],revAdj[MAX];
long long distS[MAX],distT[MAX];
Hash cntS[MAX],cntT[MAX];
int n,m,s,t;
void loadGraph(void) {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    FOR(i,1,m) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        edge[i]=Edge(u,v,c);
        adj[u].push_back(i);
        revAdj[v].push_back(i);
    }
    memset(distS,0x3f,sizeof distS);
    memset(distT,0x3f,sizeof distT);
}
void dijkstra(int s,vector<int> adj[],long long dist[],Hash cnt[]) {
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
    dist[s]=0;
    cnt[s]=1;
    q.push(make_pair(dist[s],s));
    while (!q.empty()) {
        long long w=q.top().fi;
        int u=q.top().se;
        q.pop();
        if (dist[u]<w) continue;
        FORE(it,adj[u]) {
            int v=edge[*it].other(u);
            if (dist[v]>dist[u]+edge[*it].c) {
                dist[v]=dist[u]+edge[*it].c;
                cnt[v]=cnt[u];
                q.push(make_pair(dist[v],v));
            } else if (dist[v]==dist[u]+edge[*it].c) cnt[v]+=cnt[u];
        }
    }
}
int answer(int id) {
    int u=edge[id].u;
    int v=edge[id].v;
    int c=edge[id].c;
    if (distS[u]>=INF || distT[v]>=INF) return (-2);
    if (distS[u]+distT[v]+c==distS[t] && cntS[u]*cntT[v]==cntS[t]) return (-1);
    long long tmp=distS[t]-1-distS[u]-distT[v];
    return (tmp<1?-2:c-tmp);
}
void process(void) {
    dijkstra(s,adj,distS,cntS);
    dijkstra(t,revAdj,distT,cntT);
    FOR(i,1,m) {
        int tmp=answer(i);
        if (tmp==-1) printf("YES\n");
        else if (tmp==-2) printf("NO\n");
        else printf("CAN %d\n",tmp);
    }
}
int main(void) {
    loadGraph();
    process();
    return 0;
}