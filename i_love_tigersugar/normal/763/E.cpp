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
vector<int> adj[MAX];
int numNode, numEdge, range, numQuery;

class DisjointSet {
public:
    int n, numComp;
    vector<int> lab;

    int find(int x) {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

    DisjointSet(int n = 0) {
        this->n = n;
        numComp = n;
        if (n > 0) lab.assign(n + 3, -1);
    }

    bool join(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        numComp--;
        return true;
    }

};

class Segment : DisjointSet {
public:
    int l, r;

    Segment(int _l = 0, int _r = 0) {
        l = _l; r = _r; n = numComp = 0;
        if (l > 0) {
            n = numComp = r - l + 1;
            lab.assign(n + 3, -1);
        }
    }

    Segment(const Segment &a, const Segment &b, int range) {
        if (a.l == 0) {
            *this = b;
            return;
        }
        if (b.l == 0) {
            *this = a;
            return;
        }

        assert(a.r == b.l - 1);

        l = a.l; r = b.r;

        n = a.n + b.n;
        lab.assign(n + 3, -1);
        FOR(i, 1, a.n) lab[i] = a.lab[i];
        FOR(i, 1, b.n) lab[i + a.n] = b.lab[i] < 0 ? b.lab[i] : b.lab[i] + a.n;
        numComp = a.numComp + b.numComp;

        REP(i, range) if (a.r - i >= a.l) FORE(it, adj[a.r - i]) if (b.l <= *it && *it <= b.r) {
            int x = a.n - i;
            int y = a.n + 1 + *it - b.l;
            join(x, y);
        }

        if (n > 2 * range) {
            DisjointSet dsu(2 * range);
            FOR(i, 1, 2 * range) FOR(j, i + 1, 2 * range) {
                int x = i <= range ? i : n - range + i - range;
                int y = j <= range ? j : n - range + j - range;

                if (find(x) == find(y)) dsu.join(i, j);
            }

            n = dsu.n;
            lab = dsu.lab;
        }
    }

    int getNumComp(void) const {
        return numComp;
    }
};

Segment tree[4 * MAX + 7];

void loadGraph(void) {
    scanf("%d%d%d", &numNode, &range, &numEdge);
    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        adj[u].push_back(v);
    }
}

void prepare(int i, int l, int r) {
    if (l == r) {
        tree[i] = Segment(l, r);
        return;
    }

    int m = (l + r) >> 1;
    prepare(2 * i, l, m);
    prepare(2 * i + 1, m + 1, r);
    tree[i] = Segment(tree[2 * i], tree[2 * i + 1], range);
}

Segment query(int i, int l, int r, int u, int v) {
    if (l > v || r < u || l > r || v < u) return Segment();
    if (u <= l && r <= v) return tree[i];

    int m = (l + r) >> 1;
    Segment L = query(2 * i, l, m, u, v);
    Segment R = query(2 * i + 1, m + 1, r, u ,v);
    return Segment(L, R, range);
}

Segment query(int l, int r) {
    return query(1, 1, numNode, l, r);
}

void process(void) {
    prepare(1, 1, numNode);

    scanf("%d", &numQuery);
    REP(love, numQuery) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r).getNumComp());
    }
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/