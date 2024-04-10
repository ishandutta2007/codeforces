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

const long long INF = (long long)1e18 + 7ll;

class SegmentTree {
private:
    vector<long long> tree, lazy;
    int n;

    void pushDown(int i) {
        FOR(j, 2 * i, 2 * i + 1) {
            tree[j] += lazy[i];
            lazy[j] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, long long c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            tree[i] += c;
            lazy[i] += c;
            return;
        }

        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    long long getMin(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return INF;
        if (u <= l && r <= v) return tree[i];

        pushDown(i);
        int m = (l + r) >> 1;
        long long L = getMin(2 * i, l, m, u, v);
        long long R = getMin(2 * i + 1, m + 1, r, u, v);
        return min(L, R);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        if (n > 0) {
            tree.assign(4 * n + 7, 0);
            lazy.assign(4 * n + 7, 0);
        }
    }

    void update(int l, int r, long long c) {
        update(1, 1, n, l, r, c);
    }
    long long getMin(int l, int r) {
        return getMin(1, 1, n, l, r);
    }
};

#define MAX   500500
int numNode, numQuery, cnt;
vector<pair<int, int>> children[MAX];
pair<int, int> queries[MAX];
int sta[MAX], fin[MAX], firstLeaf[MAX], lastLeaf[MAX];
long long dist[MAX];
int leaves[MAX], numLeaf;
vector<int> queryAt[MAX];
long long answer[MAX];
SegmentTree myit;

void init(void) {
    scanf("%d%d", &numNode, &numQuery);
    FOR(i, 2, numNode) {
        int p, c; scanf("%d%d", &p, &c);
        children[p].push_back(make_pair(i, c));
    }
    FOR(i, 1, numQuery) {
        int v, l, r; scanf("%d%d%d", &v, &l, &r);
        queries[i] = make_pair(l, r);
        queryAt[v].push_back(i);
    }
}

void prepareDFS(int u) {
    sta[u] = ++cnt;
    firstLeaf[u] = numNode + 1;

    if (children[u].empty()) {
        leaves[++numLeaf] = u;
        firstLeaf[u] = lastLeaf[u] = numLeaf;
    } else {
        FORE(it, children[u]) {
            int v = it->fi;
            dist[v] = dist[u] + it->se;
            prepareDFS(v);
            minimize(firstLeaf[u], firstLeaf[v]);
            maximize(lastLeaf[u], lastLeaf[v]);
        }
    }

    fin[u] = cnt;
}

void answerDFS(int u) {
    FORE(it, queryAt[u]) {
        int l = queries[*it].fi;
        int r = queries[*it].se;
        int id = lower_bound(leaves + 1, leaves + numLeaf + 1, l) - leaves;
        int jd = upper_bound(leaves + 1, leaves + numLeaf + 1, r) - leaves - 1;
//        printf("query #%d ask from %d to %d\n", *it, id, jd);
        assert(id <= jd);
        answer[*it] = myit.getMin(id, jd);
    }

    FORE(it, children[u]) {
//        printf("At node %d\n", u);
//        FOR(i, 1, numLeaf) printf("Distance to leaf %d is %lld\n", leaves[i], myit.getMin(i, i));
        int v = it->fi;
        myit.update(firstLeaf[v], lastLeaf[v], -it->se);
        myit.update(1, firstLeaf[v] - 1, it->se);
        myit.update(lastLeaf[v] + 1, numLeaf, it->se);
        answerDFS(v);
        myit.update(firstLeaf[v], lastLeaf[v], it->se);
        myit.update(1, firstLeaf[v] - 1, -it->se);
        myit.update(lastLeaf[v] + 1, numLeaf, -it->se);
    }

//    printf("At node %d\n", u);
//    FOR(i, 1, numLeaf) printf("Distance to leaf %d is %lld\n", leaves[i], myit.getMin(i, i));
}

void process(void) {
    prepareDFS(1);
    myit = SegmentTree(numLeaf);
    FOR(i, 1, numLeaf) myit.update(i, i, dist[leaves[i]]);
    answerDFS(1);
    FOR(i, 1, numQuery) cout << answer[i] << "\n";
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/