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

#define MAX   500500

vector<int> adj[MAX], haveColor[MAX], colorAt[MAX], rootOf[MAX];
int numNode, numColor;
int high[MAX], rootColor[MAX];
int label[MAX];

void loadTree(void) {
    scanf("%d%d", &numNode, &numColor);

    FOR(i, 1, numNode) {
        int t; scanf("%d", &t);
        REP(love, t) {
            int x; scanf("%d", &x);
            colorAt[i].push_back(x);
            haveColor[x].push_back(i);
        }
    }

    REP(love, numNode - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int par) {
    FORE(it, adj[u]) if (*it != par) {
        high[*it] = high[u] + 1;
        dfs(*it, u);
    }
}

void prepare(void) {
    dfs(1, -1);
    FOR(i, 1, numColor) if (!haveColor[i].empty()) {
        rootColor[i] = haveColor[i][0];
        FORE(jt, haveColor[i]) if (high[*jt] < high[rootColor[i]]) rootColor[i] = *jt;
        rootOf[rootColor[i]].push_back(i);
    }
}

void labeling(int u, int par) {
    set<int> used;
    FORE(it, colorAt[u]) if (high[rootColor[*it]] < high[u]) used.insert(label[*it]);

    int value = 1;
    FORE(it, rootOf[u]) {
        while (used.find(value) != used.end()) value++;
        label[*it] = value++;
    }

    FORE(it, adj[u]) if (*it != par) labeling(*it, u);
}

void process(void) {
    labeling(1, -1);
    FOR(i, 1, numColor) if (haveColor[i].empty()) label[i] = 1;

    int res = 0;
    FOR(i, 1, numColor) maximize(res, label[i]);
    printf("%d\n", res);
    FOR(i, 1, numColor) printf("%d ", label[i]); printf("\n");
}

int main(void) {
    loadTree();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/