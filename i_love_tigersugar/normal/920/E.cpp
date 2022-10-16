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

#define MAX   200200

int numNode, numEdge;
set<int> nodes;
vector<int> nonAdj[MAX];

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        nonAdj[u].push_back(v);
        nonAdj[v].push_back(u);
    }
    FOR(i, 1, numNode) sort(ALL(nonAdj[i]));
}

int bfs(int s) {
    queue<int> q;
    nodes.erase(s); q.push(s);
    int res = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); res++;
        vector<int> visited;
        FORE(it, nodes) if (!binary_search(ALL(nonAdj[u]), *it)) {
            visited.push_back(*it);
            q.push(*it);
        }
        FORE(it, visited) nodes.erase(*it);
    }
    return res;
}

void process(void) {
    FOR(i, 1, numNode) nodes.insert(i);
    vector<int> comps;
    while (!nodes.empty()) comps.push_back(bfs(*nodes.begin()));
    sort(ALL(comps));
    printf("%d\n", (int)comps.size());
    FORE(it, comps) printf("%d ", *it); printf("\n");
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/