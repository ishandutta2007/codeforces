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
    static const int INF = (int)1e9 + 7;

    vector<long long> sum;
    vector<pair<int, int>> maxValue;
    int n;

    void assign(int i, int l, int r, int pos, int value) {
        if (l == r) {
            sum[i] = value;
            maxValue[i] = make_pair(value, pos);
            return;
        }
        int m = (l + r) >> 1;
        if (pos > m) assign(2 * i + 1, m + 1, r, pos, value);
        else assign(2 * i, l, m, pos, value);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        maxValue[i] = max(maxValue[2 * i], maxValue[2 * i + 1]);
    }

    pair<int, int> getMax(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return make_pair(-INF, -INF);
        if (u <= l && r <= v) return maxValue[i];
        int m = (l + r) >> 1;
        pair<int, int> L = getMax(2 * i, l, m, u, v);
        pair<int, int> R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

    long long getSum(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return 0;
        if (u <= l && r <= v) return sum[i];
        int m = (l + r) >> 1;
        long long L = getSum(2 * i, l, m, u, v);
        long long R = getSum(2 * i + 1, m + 1, r, u, v);
        return L + R;
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        sum.assign(4 * n + 7, 0);
        maxValue.assign(4 * n + 7, make_pair(0, 0));
    }

    void assign(int pos, int value) {
        assign(1, 1, n, pos, value);
    }

    pair<int, int> getMax(int l, int r) const {
        return getMax(1, 1, n, l, r);
    }

    long long getSum(int l, int r) const {
        return getSum(1, 1, n, l, r);
    }
};

#define MAX   1000100

int cntDiv[MAX], value[MAX], n, q;

void prepare(void) {
    FOR(i, 1, MAX - 1) for (int j = i; j < MAX; j += i) cntDiv[j]++;
}

void process(void) {
    scanf("%d%d", &n, &q);
    FOR(i, 1, n) scanf("%d", &value[i]);
    SegmentTree myit(n);
    FOR(i, 1, n) myit.assign(i, value[i]);
    REP(love, q) {
        int t, l, r; scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            vector<pair<int, int>> pairs;
            while (true) {
                pair<int, int> tmp = myit.getMax(l, r);
                if (tmp.fi < 3) break;
                pairs.push_back(tmp);
                myit.assign(tmp.se, 0);
            }
            FORE(it, pairs) myit.assign(it->se, cntDiv[it->fi]);
        } else cout << myit.getSum(l, r) << "\n";
    }
}

int main(void) {
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/