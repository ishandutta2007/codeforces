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
    vector<bool> inQueue;
    bool FordBellman(int s,int t) {
        FOR(i,1,n) dist[i]=INF;
        FOR(i,1,n) trace[i]=-1;
        FOR(i, 1, n) inQueue[i] = false;
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
        inQueue.assign(n + 7, false);
    }
    int addEdge(int u,int v,int ca,int co) {
        int res = edge.size();
        adj[u].push_back(edge.size());
        edge.push_back(Edge(u,v,ca,co));
        adj[v].push_back(edge.size());
        edge.push_back(Edge(v,u,0,-co));
        return res;
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

    int getFlow(int id) const {
        return edge[id].flow;
    }
};

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   3333

int firstEdge[MAX], secondEdge[MAX];

void process(void) {
    int n, p, s; scanf("%d%d%d", &n, &p, &s);
    MaxFlowMinCost flow(n + 4);
    int src = n + 3;
    int snk = n + 4;
    int firstTeam = n + 1;
    int secondTeam = n + 2;
    flow.addEdge(src, firstTeam, p, 0);
    flow.addEdge(src, secondTeam, s, 0);

    FOR(i, 1, n) flow.addEdge(i, snk, 1, 0);
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        firstEdge[i] = flow.addEdge(firstTeam, i, 1, -x);
    }
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        secondEdge[i] = flow.addEdge(secondTeam, i, 1, -x);
    }
    printf("%d\n", -flow.getFlow(src, snk).se);
    vector<int> toFirst, toSecond;
    FOR(i, 1, n) {
        if (flow.getFlow(firstEdge[i])) toFirst.push_back(i);
        if (flow.getFlow(secondEdge[i])) toSecond.push_back(i);
    }
    FORE(it, toFirst) printf("%d ", *it); printf("\n");
    FORE(it, toSecond) printf("%d ", *it); printf("\n");
}
int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/