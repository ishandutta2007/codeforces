#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/
#define MAX   100100
int numNode;
vector<int> children[MAX];
int maxHeight[MAX];
vector<int> order;
int par[MAX], needPar[MAX];

void loadTree(void) {
    scanf("%d", &numNode);
    FOR(i, 2, numNode) {
        int x; scanf("%d", &x);
        needPar[i] = x + 1;
        children[x + 1].push_back(i);
    }
}

void calcMaxHeight(int u) {
    FORE(it, children[u]) {
        calcMaxHeight(*it);
        maximize(maxHeight[u], maxHeight[*it] + 1);
    }
}

bool CompareChild(const int &x, const int &y) {
    return maxHeight[x] < maxHeight[y];
}
void buildOrder(int u) {
    order.push_back(u);
    sort(ALL(children[u]), CompareChild);
    FORE(it, children[u]) buildOrder(*it);
}

void process(void) {
    calcMaxHeight(1);
    buildOrder(1);
    FOR(i, 1, numNode - 1) par[order[i]] = order[i - 1];
    vector<int> changes;
    FOR(i, 1, numNode - 1) {
        int u = order[i];
        while (par[u] != needPar[u]) {
            changes.push_back(u);
            par[u] = par[par[u]];
        }
    }

    FORE(it, order) printf("%d ", *it - 1); printf("\n");
    printf("%d\n", (int)changes.size());
    FORE(it, changes) printf("%d ", *it - 1); printf("\n");
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/