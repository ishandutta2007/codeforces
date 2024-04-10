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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   5050

const int INF = (int) 1e9 + 7;

struct Store {
    int place, have, price;

    Store() {
        place = have = price = 0;
    }

    void input(void) {
        scanf("%d%d%d", &place, &have, &price);
    }

    bool operator < (const Store &s) const {
        return price < s.price;
    }
};

vector<int> adj[MAX];
int dist[MAX][MAX];
Store stores[MAX];
int numNode, numEdge, numStore, numQuery;

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d", &numStore);
    FOR(i, 1, numStore) stores[i].input();
    sort(stores + 1, stores + numStore + 1);
}

void bfs(int s, int dist[]) {
    queue<int> q;
    dist[s] = 0; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        FORE(it, adj[u]) if (dist[*it] >= INF) {
            dist[*it] = dist[u] + 1;
            q.push(*it);
        }
    }
}
void prepare(void) {
    memset(dist, 0x3f, sizeof dist);
    FOR(i, 1, numNode) bfs(i, dist[i]);
}

bool ok(int place, int need, int allow, int maxDist) {
    FOR(i, 1, numStore) if (dist[place][stores[i].place] <= maxDist) {
        int use = min(need, stores[i].have);
        if (1LL * use * stores[i].price > allow) return false;
        need -= use;
        allow -= use * stores[i].price;
    }
    return need == 0 && allow >= 0;
}
int answerQuery(int place, int need, int allow) {
    if (!ok(place, need, allow, numNode + 1)) return -1;
    int L = 0;
    int R = numNode + 1;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return ok(place, need, allow, L) ? L : R;
        int M = (L + R) >> 1;
        if (ok(place, need, allow, M)) R = M; else L = M + 1;
    }
}
void process(void) {
    scanf("%d", &numQuery);
    REP(love, numQuery) {
        int place, need, allow; scanf("%d%d%d", &place, &need, &allow);
        printf("%d\n", answerQuery(place, need, allow));
    }
}

int main(void) {
    loadGraph();
    prepare();
    process();
    return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/