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

const string YES = "YES";
const string NO = "NO";

void noAnswer(void) {
    cout << NO << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   3030
int numNode, root;
int par[MAX], numLess[MAX], res[MAX];
vector<int> children[MAX];

void loadTree(void) {
    scanf("%d", &numNode);
    FOR(i, 1, numNode) {
        scanf("%d%d", &par[i], &numLess[i]);
        if (par[i] == 0) root = i; else children[par[i]].push_back(i);
    }
}

vector<int> getNode(int u) {
    vector<int> nodes;
    FORE(it, children[u]) {
        vector<int> tmp = getNode(*it);
        FORE(jt, tmp) nodes.push_back(*jt);
    }

    if (numLess[u] < 0 || numLess[u] > nodes.size()) noAnswer();
    nodes.insert(nodes.begin() + numLess[u], u);
    return nodes;
}

void process(void) {
    vector<int> nodes = getNode(root);
    REP(i, nodes.size()) res[nodes[i]] = i + 1;

    cout << YES << endl;
    FOR(i, 1, numNode) printf("%d ", res[i]); printf("\n");
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/