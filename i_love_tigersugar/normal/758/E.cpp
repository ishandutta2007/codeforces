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

class FenwickTree {
private:
    vector<long long> v;
    int n;

    long long get(int x) const {
        long long res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }

public:
    FenwickTree(int n = 0) {
        this->n = n;
        v.assign(n + 7, 0);
    }

    void update(int x, long long d) {
        for (; x <= n; x += x & -x) v[x] += d;
    }

    long long get(int l, int r) const {
        return l == 1 ? get(r) : get(r) - get(l - 1);
    }
};

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void update(int i, int l, int r, int pos, int val) {
        if (l == r) {
            tree[i] = val;
            return;
        }

        int m = (l + r) >> 1;
        if (pos > m) update(2 * i + 1, m + 1, r, pos, val);
        else update(2 * i, l, m, pos, val);
        tree[i] = tree[2 * i + 1] < 0 ? tree[2 * i] : tree[2 * i + 1];
    }

    int get(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return -1;
        if (u <= l && r <= v) return tree[i];

        int m = (l + r) >> 1;
        int R = get(2 * i + 1, m + 1, r, u, v);
        if (R >= 0) return R;
        return get(2 * i, l, m, u, v);
    }

    void debug(int i, int l, int r) const {
        printf("NODE %d (%d - %d): %d\n", i, l, r, tree[i]);
        if (l == r) return;

        int m = (l + r) >> 1;
        debug(2 * i, l, m);
        debug(2 * i + 1, m + 1, r);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, -1);
    }

     void insert(int pos, int val) {
         update(1, 1, n, pos, val);
     }
     void remove(int pos) {
         update(1, 1, n, pos, -1);
     }
     int get(int l, int r) const {
         return get(1, 1, n, l, r);
     }

     void debug(void) const {
         debug(1, 1, n);
     }
};

const int MIN_W = 1;
const int MIN_S = 0;
struct Edge {
    int par, child, weight, strength, delta;

    Edge(int p = 0, int c = 0, int w = 0, int s = 0) {
        par = p; child = c; weight = w; strength = s;
    }

    void reduce(int delta) {
        weight -= delta;
        strength -= delta;
        assert(weight >= MIN_W && strength >= MIN_S);
    }

    int canChange(void) const {
        return min(weight - MIN_W, strength - MIN_S);
    }

    void printEdge(void) const {
        printf("%d %d %d %d\n", par, child, weight, strength);
    }
};

#define MAX   200200
Edge edges[MAX];
vector<int> children[MAX];
int n, cnt, sta[MAX], fin[MAX], parEdge[MAX];

void loadTree(void) {
    scanf("%d", &n);
    REP(i, n - 1) {
        int p, c, w, s; scanf("%d%d%d%d", &p, &c, &w, &s);
        edges[i] = Edge(p, c, w, s);
        parEdge[c] = i;
        children[p].push_back(i);
    }
}

void dfs(int u) {
    sta[u] = ++cnt;
    FORE(it, children[u]) dfs(edges[*it].child);
    fin[u] = cnt;
}

bool compare(const int &x, const int &y) {
    return sta[x] > sta[y];
}
void noAnswer(void) {
    printf("-1\n");
    exit(0);
}
void process(void) {
    dfs(1);

    vector<int> nodes;
    FOR(i, 1, n) nodes.push_back(i);
    sort(ALL(nodes), compare);

    FenwickTree bit(n);
    SegmentTree myit(n);
    REP(i, n - 1) bit.update(sta[edges[i].child], edges[i].weight);
    REP(i, n - 1) myit.insert(sta[edges[i].child], i);

    FORE(it, nodes) if (*it != 1) {
        int id = parEdge[*it];

        long long needChange = bit.get(sta[*it] + 1, fin[*it]) - edges[id].strength;

        //printf("At %d need %lld\n", edges[id].child, needChange);
        while (needChange > 0) {
            int recEdge = myit.get(sta[*it] + 1, fin[*it]);
            if (recEdge < 0) {
                //printf("FAIL at %d\n", edges[id].child);
                noAnswer();
            }
            int recChild = edges[recEdge].child;

            int change = edges[recEdge].strength - bit.get(sta[recChild] + 1, fin[recChild]);
            minimize(change, edges[recEdge].canChange());
            minimize(change, needChange);

            if (change == 0) {
                myit.remove(sta[recChild]);
                continue;
            }

            //printf("Reduce %d at %d\n", change, edges[recEdge].child);
            edges[recEdge].reduce(change);
            bit.update(sta[recChild], -change);
            needChange -= change;
        }
    }

    printf("%d\n", n);
    REP(i, n - 1) edges[i].printEdge();
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/