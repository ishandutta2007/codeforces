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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX_DEG   33
#define MAX_NODE   200200
int numNode, numEdge, maxDeg;
vector<pair<int, int>> adj[MAX_NODE];
vector<int> revAdj[MAX_NODE];
int block[MAX_DEG];
int chain[MAX_DEG][MAX_DEG][MAX_DEG];
int result;
vector<int> available;

void loadGraph(void) {
    scanf("%d%d%d", &numNode, &numEdge, &maxDeg);
    REP(love, numEdge) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(make_pair(w, v));
        revAdj[v].push_back(u);
    }
    FOR(i, 1, numNode) sort(ALL(adj[i]));
}

void loadCondition(void) {
    FOR(v, 1, numNode) {
        map<pair<int, int>, int> cnt;
        FORE(it, revAdj[v]) {
            int u = *it;
            int deg = adj[u].size();
            REP(j, adj[u].size()) if (adj[u][j].se == v) cnt[make_pair(deg, j)]++;
        }
        FORE(it, cnt) {
            if (it->se > 1) block[it->fi.fi] |= MASK(it->fi.se);
            FORE(jt, cnt) if (it->fi != jt->fi) chain[it->fi.fi][it->fi.se][jt->fi.fi] |= MASK(jt->fi.se);
        }
    }
}


void backtrack(int pos) {
    if (pos > maxDeg) {
        result++;
        return;
    }

    vector<int> old = available;
    REP(val, pos) if (BIT(available[pos], val)) {
        FOR(next, pos + 1, maxDeg) available[next] &= ~chain[pos][val][next];
        backtrack(pos + 1);
        FOR(next, pos + 1, maxDeg) available[next] = old[next];
    }
}

void process(void) {
    available.assign(maxDeg + 1, 0);
    FOR(i, 1, maxDeg) available[i] = (MASK(maxDeg) - 1) ^ block[i];
    backtrack(1);
    cout << result << endl;
}

int main(void) {
    loadGraph();
    loadCondition();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/