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

#define MAX   100100
const char YES[] = "YES";
const char NO[] = "NO";

vector<int> adj[MAX], haveColor[MAX];
int color[MAX];
int par[MAX], sta[MAX], fin[MAX], n, cnt;

void loadTree(void) {
    scanf("%d", &n);
    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, n) {
        scanf("%d", &color[i]);
        haveColor[color[i]].push_back(i);
    }
}

void dfs(int u) {
    sta[u] = ++cnt;
    FORE(it, adj[u]) if (*it != par[u]) {
        par[*it] = u;
        dfs(*it);
    }
    fin[u] = cnt;
}

void answer(int node) {
    if (node > 0) printf("%s\n%d\n", YES, node);
    else printf("%s\n", NO);
    exit(0);
}

bool checkSubTree(int u) {
    int c = color[u];

    int L = lower_bound(ALL(haveColor[c]), sta[u]) - haveColor[c].begin();
    int R = upper_bound(ALL(haveColor[c]), fin[u]) - haveColor[c].begin();
    return R - L == fin[u] - sta[u] + 1;
}
bool checkParTree(int u) {
    if (u == 1) return true;

    int c = color[par[u]];

    int L = lower_bound(ALL(haveColor[c]), sta[u]) - haveColor[c].begin();
    int R = upper_bound(ALL(haveColor[c]), fin[u]) - haveColor[c].begin();
    return haveColor[c].size() - (R - L) == n - (fin[u] - sta[u] + 1);
}

bool checkNode(int u) {
    FORE(it, adj[u]) {
        if (par[*it] == u && !checkSubTree(*it)) return false;
        if (par[u] == *it && !checkParTree(u)) return false;
    }
    return true;
}

void process(void) {
    dfs(1);
    REP(i, MAX) if (!haveColor[i].empty()) {
        FORE(it, haveColor[i]) *it = sta[*it];
        sort(ALL(haveColor[i]));
    }

    FOR(i, 1, n) if (checkNode(i)) answer(i);
    answer(-1);
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/