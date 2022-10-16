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

const int INF = (int)1e9;

class SegmentTreeMin {
private:
    vector<int> lazy;
    int n;

    void update(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) return minimize(lazy[i], c);

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
    }

public:
    SegmentTreeMin(int n = 0) {
        this->n = n;
        lazy.assign(4 * n + 7, INF);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    int get(int x) const {
        int res = INF;
        int i = 1, l = 1, r = n;
        while (true) {
            minimize(res, lazy[i]);
            if (l == r) return res;
            int m = (l + r) >> 1;
            if (x > m) {
                i = 2 * i + 1; l = m + 1;
            } else {
                i = 2 * i; r = m;
            }
        }
    }
};

class SegmentTreeMax {
private:
    vector<pair<int, int> > tree;
    int n;

    void build(int i, int l, int r) {
        if (l == r) {
            tree[i] = make_pair(-1, r);
            return;
        }
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    void assign(int i, int l, int r, int x, int v) {
        if (l == r) {
            tree[i] = make_pair(v, x);
            return;
        }

        int m = (l + r) >> 1;
        if (x > m) assign(2 * i + 1, m + 1, r, x, v);
        else assign(2 * i, l, m, x, v);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    pair<int, int> getMax(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return make_pair(-1, 0);
        if (u <= l && r <= v) return tree[i];

        int m = (l + r) >> 1;
        pair<int, int> L = getMax(2 * i, l, m, u, v);
        pair<int, int> R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

public:
    SegmentTreeMax(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, make_pair(-1, -1));
        build(1, 1, n);
    }

    void assign(int x, int v) {
        assign(1, 1, n, x, v);
    }

    pair<int, int> getMax(int l, int r) const {
        return getMax(1, 1, n, l, r);
    }
};

struct Query {
    #define GET_MAX   1
    #define UPDATE   2

    int type, l, r, pos, value;
    bool good;

    Query() {
        type = l = r = pos = value = 0;
        good = false;
    }

    void input(void) {
        scanf("%d", &type);
        if (type == GET_MAX) scanf("%d%d%d", &l, &r, &value);
        else scanf("%d%d", &pos, &value);
    }
};

void noAnswer(void) {
    cout << "NO" << endl;
    exit(0);
}

#define MAX   300300

int n, q;
Query queries[MAX];
int maxValue[MAX];
int hold[MAX], res[MAX];

void init(void) {
    scanf("%d%d", &n, &q);
    FOR(i, 1, q) queries[i].input();
}

void process(void) {
    SegmentTreeMax maxUpdate(n);
    SegmentTreeMin queryLimit(n);

    memset(maxValue, -1, sizeof maxValue);
    FOR(i, 1, q) {
        if (queries[i].type == GET_MAX) {
            int L = queries[i].l, R = queries[i].r, V = queries[i].value;
            queryLimit.update(L, R, V);
            int tmp = maxUpdate.getMax(L, R).fi;
            if (tmp > V) noAnswer();
            queries[i].good = tmp == V;
        } else {
            int pos = queries[i].pos;
            if (maxValue[pos] < 0) maxValue[pos] = queryLimit.get(pos);
            maxUpdate.assign(pos, queries[i].value);
        }
    }
    FOR(i, 1, n) if (maxValue[i] < 0) maxValue[i] = queryLimit.get(i);

    SegmentTreeMax maxSeq(n);
    FOR(i, 1, n) maxSeq.assign(i, maxValue[i]);

    memset(hold, -1, sizeof hold);
    FOR(i, 1, q) {
        if (queries[i].type == GET_MAX) {
            pair<int, int> v = maxSeq.getMax(queries[i].l, queries[i].r);
            if (v.fi != queries[i].value) noAnswer();
            if (!queries[i].good) {
                assert(hold[v.se] < 0);
                hold[v.se] = i;
            }
        } else maxSeq.assign(queries[i].pos, queries[i].value);
    }

    set<pair<int, int> > freePos;

    int sumOr = 0;
    FOR(i, 1, n) {
        if (hold[i] > 0) {
            res[i] = maxValue[i];
            sumOr |= maxValue[i];
        } else freePos.insert(make_pair(maxValue[i], i));
    }

    FORD(i, 30, 0) if (!BIT(sumOr, i)) {
        __typeof(freePos.begin()) it = freePos.lower_bound(make_pair(MASK(i), -1));
        if (it == freePos.end()) continue;

        pair<int, int> tmp = *it;
        res[tmp.se] |= MASK(i);
        sumOr |= MASK(i);
        tmp.fi -= MASK(i);

        freePos.erase(it);
        freePos.insert(tmp);
    }

    printf("YES\n");
    FOR(i, 1, n) printf("%d ", res[i]); printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/