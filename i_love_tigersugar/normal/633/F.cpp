#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i, a, b) for (int i=(a), _b=(b);i<=_b;i=i + 1)
#define FORD(i, b, a) for (int i=(b), _a=(a);i >= _a;i=i-1)
#define REP(i, n) for (int i=0, _n=(n);i<_n;i=i + 1)
#define FORE(i, v) for (__typeof((v).begin()) i=(v).begin();i != (v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X, class Y>
    void minimize(X &x, const Y &y) {
        if (x>y) x=y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x<y) x=y;
    }

template<class T>
    void update(pair<T, T> &x, const T &y) {
        if (y>x.fi) {
            x.se = x.fi;
            x.fi = y;
        } else if (y > x.se) x.se = y;
    }

template<class T>
    void keepTopThree(vector<T> &x, const T &y) {
        x.push_back(y);
        FORD(i, (int)x.size() - 1, 1) {
            if (x[i] > x[i - 1]) swap(x[i], x[i - 1]);
            else break;
        }
        while (x.size() > 3) x.pop_back();
    }

vector<int> adj[MAX];
int n, val[MAX];
typedef pair<long long, int> LI;



void loadTree(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &val[i]);
    REP(love, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
long long maxAsRoot[MAX], maxAsLCA[MAX], maxSubTree[MAX];
long long separateDFS(int u, int p) {
    long long res = -1;
    maxAsRoot[u] = val[u];
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        maximize(res, separateDFS(v, u));
        maximize(maxAsRoot[u], maxAsRoot[v] + val[u]);
        maximize(maxSubTree[u], maxSubTree[v]);
    }
    pair<long long, long long> best(-1, -1);
    maxAsLCA[u] = maxAsRoot[u];
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        update(best, maxAsRoot[v]);
    }
    if (best.se >= 0) maximize(maxAsLCA[u], best.fi + best.se + val[u]);
    maximize(maxSubTree[u], maxAsLCA[u]);
    best = make_pair(-1, -1);
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        update(best, maxSubTree[v]);
    }
    if (best.se >= 0) maximize(res, best.fi + best.se);
    return (res);
}
long long separateCase(void) {
    return (separateDFS(1, -1));
}
long long maxRootWithPath[MAX];
long long dependDFS(int u, int p) {
    long long res = -1;
    maxRootWithPath[u] = -1;
    pair<LI, LI> bestAsRoot(make_pair(-1, -1), make_pair(-1, -1));
    pair<LI, LI> bestSubTree(make_pair(-1, -1), make_pair(-1, -1));
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        maximize(res, dependDFS(v, u));
        if (maxRootWithPath[v] >= 0) maximize(maxRootWithPath[u], maxRootWithPath[v] + val[u]);
        maximize(maxRootWithPath[u], maxSubTree[v] + val[u]);
        update(bestAsRoot, make_pair(maxAsRoot[v] + val[u], v));
        update(bestSubTree, make_pair(maxSubTree[v], v));
    }
    REP(i, 2) REP(j, 2) {
        pair<long long, int> &asRoot = i ? bestAsRoot.fi : bestAsRoot.se;
        pair<long long, int> &subTree = j ? bestSubTree.fi : bestSubTree.se;
        if (asRoot.se < 0 || subTree.se < 0 || asRoot.se == subTree.se) continue;
        maximize(maxRootWithPath[u], asRoot.fi + subTree.fi);
    }
    maximize(res, maxRootWithPath[u]);
    pair<LI, LI> bestWithPath(make_pair(-1, -1), make_pair(-1, -1));
    pair<LI, LI> bestWithoutPath(make_pair(-1, -1), make_pair(-1, -1));
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        if (maxRootWithPath[v] >= 0) update(bestWithPath, make_pair(maxRootWithPath[v], v));
        update(bestWithoutPath, make_pair(maxAsRoot[v], v));
    }
    REP(i, 2) REP(j, 2) {
        pair<long long, int> &withPath = i ? bestWithPath.fi : bestWithPath.se;
        pair<long long, int> &withoutPath = j ? bestWithoutPath.fi : bestWithoutPath.se;
        if (withPath.se < 0 || withoutPath.se < 0 || withPath.se == withoutPath.se) continue;
        maximize(res, withPath.fi + withoutPath.fi + val[u]);
    }
    vector<pair<long long, int> > allRoot, allSubTree;
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        keepTopThree(allRoot, make_pair(maxAsRoot[v], v));
        keepTopThree(allSubTree, make_pair(maxSubTree[v], v));
    }
    FORE(it, allRoot) FORE(jt, allRoot) FORE(kt, allSubTree)
        if (it->se != jt->se && jt->se != kt->se && kt->se != it->se)
            maximize(res, it->fi + jt->fi + kt->fi + val[u]);
    return (res);
}
long long dependCase(void) {
    return (dependDFS(1, -1));
}
void process(void) {
    long long separate=separateCase();
    long long depend=dependCase();
    //FOR(i, 1, n) printf("max route %d is %lld\n", i, maxRootWithPath[i]);
    cerr<< separate <<endl;
    cerr<< depend <<endl;
    cout<< max(separate, depend) <<endl;
}
int main(void) {
    loadTree();
    process();
    return 0;
}