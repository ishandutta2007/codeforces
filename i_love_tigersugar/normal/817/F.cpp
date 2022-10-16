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

class SegmentTree {
private:
    vector<int> tree, lazy, rev;
    int n;

    void applyChange(int i, int l, int r, int c) {
        if (c >= 0) {
            tree[i] = c * (r - l + 1);
            lazy[i] = c;
            rev[i] = false;
        } else {
            tree[i] = (r - l + 1) - tree[i];
            if (lazy[i] < 0) rev[i] ^= 1;
            else {
                lazy[i] ^= 1; rev[i] = false;
            }
        }
    }
    void pushDown(int i, int l, int r) {
        assert(!rev[i] || lazy[i] < 0);
        if (!rev[i] && lazy[i] < 0) return;
        int m = (l + r) >> 1;
        applyChange(2 * i, l, m, rev[i] ? -1 : lazy[i]);
        applyChange(2 * i + 1, m + 1, r, rev[i] ? -1 : lazy[i]);
        rev[i] = false; lazy[i] = -1;
    }

    void update(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) return applyChange(i, l, r, c);

        pushDown(i, l, r);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
        rev.assign(4 * n + 7, 0);
    }

    void update(int l, int r, int c) {
        update(1, 1, n, l, r, c);
    }

    int findPos(void) {
        assert(tree[1] < n);

        int i = 1, l = 1, r = n;
        while (true) {
            if (l == r) return r;

            pushDown(i, l, r);
            int m = (l + r) >> 1;
            if (tree[2 * i] == m - l + 1) {
                i = 2 * i + 1; l = m + 1;
            } else {
                i = 2 * i; r = m;
            }
        }
    }
};

struct Query {
    #define INSERT   1
    #define REMOVE   2
    #define REVERSE   3

    int type;
    long long L, R;

    Query() {
        type = L = R = 0;
    }
};

istream& operator >> (istream &is, Query &q) {
    return is >> q.type >> q.L >> q.R;
}

const long long INF = (long long)1e18 + 7LL;

#define MAX   100100

vector<long long> values;
Query queries[MAX];
int numQuery;

void init(void) {
    cin >> numQuery;
    REP(i, numQuery) cin >> queries[i];

    REP(i, numQuery) {
        values.push_back(queries[i].L);
        values.push_back(queries[i].R + 1);
    }
    values.push_back(1);
    values.push_back(INF + 1);

    sort(ALL(values));
    values.resize(unique(ALL(values)) - values.begin());
}

void process(void) {
    SegmentTree myit(values.size() - 1);
    REP(i, numQuery) {
        int type;
        if (queries[i].type == INSERT) type = 1;
        else if (queries[i].type == REMOVE) type = 0;
        else type = -1;

        int L = lower_bound(ALL(values), queries[i].L) - values.begin() + 1;
        int R = lower_bound(ALL(values), queries[i].R + 1) - values.begin() + 1;
        myit.update(L, R - 1, type);

        int res = myit.findPos();
        cout << values[res - 1] << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/