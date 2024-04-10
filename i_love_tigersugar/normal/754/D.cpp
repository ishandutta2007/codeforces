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

/* Author: GS.PVH */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

class FenwickTree {
private:
    vector<int> v;
    int n;

    void _update(int x, int d) {
        for (; x <= n; x += x & -x) v[x] += d;
    }

public:
    FenwickTree(int n = 0) {
        this->n = n;
        v.assign(n + 7, 0);
    }

    void update(int l, int r) {
        _update(l, 1);
        if (r + 1 <= n) _update(r + 1, -1);
    }

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }
};

#define MAX   700700
const int INF = (int)1e9 + 7;

pair<int, int> segments[MAX];
vector<int> events[MAX];
vector<int> points;
int n, m;

void init(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d%d", &segments[i].fi, &segments[i].se);
}

void process(void) {
    points.push_back(-INF);
    points.push_back(INF);
    FOR(i, 1, n) {
        points.push_back(segments[i].fi);
        points.push_back(segments[i].se + 1);
    }

    sort(ALL(points));
    points.resize(unique(ALL(points)) - points.begin());
    FOR(i, 1, n) {
        int L = lower_bound(ALL(points), segments[i].fi) - points.begin();
        int R = lower_bound(ALL(points), segments[i].se + 1) - points.begin() - 1;
        events[L].push_back(R);
    }

    FenwickTree bit(points.size() - 1);

    pair<int, int> best(0, 0);
    int j = 0;
    REP(i, points.size() - 1) {
        FORE(it, events[i]) bit.update(i + 1, *it + 1);
        if (j < i) j = i;
        while (j < points.size() - 1 && bit.get(j + 1) >= m) j++;

        if (j > i && points[j] - points[i] > best.se - best.fi) best = make_pair(points[i], points[j]);
    }

    printf("%d\n", best.se - best.fi); best.se--;
    if (best.se < best.fi) {
        FOR(i, 1, m) printf("%d ", i); printf("\n");
        return;
    }

    int need = m;
    FOR(i, 1, n) if (segments[i].fi <= best.fi && best.se <= segments[i].se)
        if (--need >= 0) printf("%d ", i);
    printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/