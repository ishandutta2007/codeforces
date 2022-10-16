#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/

class MaxFlowMinCost {
    private:
    static const int INF=(int)1e9+7;
    struct Edge {
        int from,to,capa,flow,cost;
        Edge() {
            from=to=capa=flow=cost=0;
        }
        Edge(int u,int v,int ca,int co) {
            from=u;to=v;capa=ca;flow=0;cost=co;
        }
        int residental(void) const {
            return (capa-flow);
        }
    };
    int n;
    vector<vector<int> > adj;
    vector<Edge> edge;
    vector<int> dist,trace;
    bool FordBellman(int s,int t) {
        FOR(i,1,n) dist[i]=INF;
        FOR(i,1,n) trace[i]=-1;
        vector<bool> inQueue(n+7,false);
        queue<int> q;
        dist[s]=0;q.push(s);inQueue[s]=true;
        while (!q.empty()) {
            int u=q.front();q.pop();inQueue[u]=false;
            FORE(it,adj[u]) if (edge[*it].residental()>0) {
                int v=edge[*it].to;
                if (dist[v]>dist[u]+edge[*it].cost) {
                    dist[v]=dist[u]+edge[*it].cost;
                    trace[v]=*it;
                    if (!inQueue[v]) {
                        q.push(v);inQueue[v]=true;
                    }
                }
            }
        }
        return (dist[t]<INF);
    }
    public:
    MaxFlowMinCost() {
        n=0;
    }
    MaxFlowMinCost(int n) {
        this->n=n;
        adj.assign(n+7,vector<int>());
        dist.assign(n+7,0);
        trace.assign(n+7,0);
    }
    void addEdge(int u,int v,int ca,int co) {
        adj[u].push_back(edge.size());
        edge.push_back(Edge(u,v,ca,co));
        adj[v].push_back(edge.size());
        edge.push_back(Edge(v,u,0,-co));
    }
    pair<int,int> getFlow(int s,int t) {
        int totFlow=0;
        int totCost=0;
        while (FordBellman(s,t)) {
            int delta=INF;
            for (int u=t;u!=s;u=edge[trace[u]].from) delta=min(delta,edge[trace[u]].residental());
            for (int u=t;u!=s;u=edge[trace[u]].from) {
                edge[trace[u]].flow+=delta;
                edge[trace[u]^1].flow-=delta;
            }
            totFlow+=delta;
            totCost+=delta*dist[t];
        }
        return (make_pair(totFlow,totCost));
    }
};

#define MAX   100100
#define COUNT   4
const int MOD = 7;

int value[MAX], next[MAX][MOD], n;
vector<int> pos[MAX];

void process(void) {
    if (scanf("%d", &n) != 1) exit(EXIT_SUCCESS);
    FOR(i, 1, n) scanf("%d", &value[i]);

    FOR(j, n, n + 1) REP(i, MOD) next[j][i] = n + 1;
    FORD(i, n - 1, 1) {
        REP(j, MOD) next[i][j] = next[i + 1][j];
        next[i][value[i + 1] % MOD] = i + 1;
    }

    REP(i, MAX) pos[i].clear();
    FOR(i, 1, n) pos[value[i]].push_back(i);

    MaxFlowMinCost mfmc(2 * n + 3);
    int src = 2 * n + 1;
    int snk = 2 * n + 2;
    int fake = 2 * n + 3;

    #define IN(x) (2 * (x) - 1)
    #define OUT(x) (2 * (x))

    FOR(i, 1, n) {
        mfmc.addEdge(fake, IN(i), 1, 0);
        mfmc.addEdge(IN(i), OUT(i), 1, -1);
        mfmc.addEdge(OUT(i), snk, 1, 0);

        int nextSame = i, nextUp = i, nextDown = i;
        REP(pmp, COUNT) {
            nextSame = next[nextSame][value[i] % MOD];
            if (nextSame <= n) mfmc.addEdge(OUT(i), IN(nextSame), 1, 0);

            int tmp = upper_bound(ALL(pos[value[i] + 1]), nextUp) - pos[value[i] + 1].begin();
            nextUp = tmp < pos[value[i] + 1].size() ? pos[value[i] + 1][tmp] : n + 1;
            if (nextUp <= n) mfmc.addEdge(OUT(i), IN(nextUp), 1, 0);

            tmp = upper_bound(ALL(pos[value[i] - 1]), nextDown) - pos[value[i] - 1].begin();
            nextDown = tmp < pos[value[i] - 1].size() ? pos[value[i] - 1][tmp] : n + 1;
            if (nextDown <= n) mfmc.addEdge(OUT(i), IN(nextDown), 1, 0);
        }
    }

    mfmc.addEdge(src, fake, COUNT, 0);
    printf("%d\n", -mfmc.getFlow(src, snk).se);
}

int main(void) {
    while (true) process();
    return 0;
}