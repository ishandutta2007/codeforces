#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
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

const string YES = "Yes";
const string NO = "No";

void noAnswer(void) {
    cout << NO << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   100100
int n;
vector<int> adj[MAX];

void loadTree(void) {
    scanf("%d", &n);
    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void process(void) {
    int numBigDeg = 0;
    FOR(i, 1, n) if (adj[i].size() > 2) numBigDeg++;
    if (numBigDeg > 1) noAnswer();

    int root = 1;
    FOR(i, 1, n) if (adj[i].size() > adj[root].size()) root = i;

    if (adj[root].size() == 1) {
        cout << YES << endl;
        printf("1\n1 2\n");
        return;
    }

    vector<int> leaves;
    FOR(i, 1, n) if (adj[i].size() == 1) leaves.push_back(i);
    cout << YES << endl;
    printf("%d\n", (int)leaves.size());
    FORE(it, leaves) printf("%d %d\n", root, *it);
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/