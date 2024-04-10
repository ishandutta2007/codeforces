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
    vector<int> tree;
    int n;

    int getMax(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return -1;
        if (u <= l && r <= v) return tree[i];

        int m = (l + r) >> 1;
        int L = getMax(2 * i, l, m, u, v);
        int R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, 0);
    }

    void reset(void) {
        FORE(it, tree) *it = 0;
    }

    void update(int x, int v) {
        int l = 1, r = n, i = 1;

        while (true) {
            maximize(tree[i], v);
            if (l == r) return;
            int m = (l + r) >> 1;
            if (x > m) {
                i = 2 * i + 1; l = m + 1;
            } else {
                i = 2 * i; r = m;
            }
        }
    }

    int getMax(int l, int r) const {
        return getMax(1, 1, n, l, r);
    }
};

#define MAX   200200
#define MAGIC   150

int numLevel, numSegment, numQuery;
pair<int, int> segments[MAX];
vector<pair<int, int> > lowAt[MAX], highAt[MAX];
int maxHigh[MAX];
vector<pair<int, int> > newSegment;
vector<pair<int, int> > queryAt[MAX];
int answer[MAX];
SegmentTree myit;

void init(void) {
    scanf("%d%d", &numLevel, &numSegment);
    FOR(i, 1, numSegment) {
        int l, r; scanf("%d%d", &l, &r);
        segments[i] = make_pair(l, r);
        lowAt[l].push_back(make_pair(r, i));
        highAt[r].push_back(make_pair(l, i));
    }
    scanf("%d", &numQuery);
    FOR(i, 1, numQuery) {
        int l, r; scanf("%d%d", &l, &r);
        queryAt[r].push_back(make_pair(l, i));
    }

    FOR(i, 1, numLevel) sort(ALL(lowAt[i]));
    myit = SegmentTree(numLevel);
}

bool compFirst(const pair<int, int> &a, const pair<int, int> &b) {
    return a.fi < b.fi;
}

void calcMaxHigh(int limit) {
    myit.reset();

    FORD(i, limit, 1) {
        int j = upper_bound(ALL(lowAt[i]), make_pair(limit, -1), compFirst) - lowAt[i].begin() - 1;
        if (j >= 0) maxHigh[i] = myit.getMax(i + 1, lowAt[i][j].fi);
        maximize(maxHigh[i], i);
        myit.update(i, maxHigh[i]);
    }

//    printf("construct %d\n", limit);
//    FOR(i, 1, limit) printf("%d ", maxHigh[i]); printf("\n");
}

int query(int l) {
    int r = maxHigh[l];
    int res = r;
    FORE(it, newSegment) if (l <= segments[it->fi].fi && segments[it->fi].fi <= r) maximize(res, it->se);
    return res;
}

void addSegment(int segID) {
    //printf("ADD SEG %d (%d, %d)\n", segID, segments[segID].fi, segments[segID].se);
    int L = segments[segID].fi, R = segments[segID].se;
    FORE(it, newSegment) if (segments[it->fi].fi <= L && L <= it->se) maximize(it->se, R);
    newSegment.push_back(make_pair(segID, R));

    if (newSegment.size() > numSegment / MAGIC) {
        newSegment.clear();
        calcMaxHigh(R);
    }
}

void process(void) {
    FOR(i, 1, numLevel) maxHigh[i] = i;

    FOR(r, 1, numLevel) {
        FORE(it, highAt[r]) addSegment(it->se);

        //printf("At lim %d\n", r);
        //FOR(i, 1, numLevel) printf("%d ", maxHigh[i]); printf("\n");
        //FORE(it, newSegment) printf("newseg #%d range %d\n", it->fi, it->se);
        FORE(it, queryAt[r]) answer[it->se] = query(it->fi);
    }

    FOR(i, 1, numQuery) printf("%d\n", answer[i]);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/