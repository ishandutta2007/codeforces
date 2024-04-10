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

pair<int, long long> operator + (const pair<int, long long> &a, const pair<int, long long> &b) {
    return make_pair(a.fi + b.fi, a.se + b.se);
}

int prev(int x, int mod) {
    while ((x - mod) % 2 != 0) x--;
    return x;
}
int next(int x, int mod) {
    while ((x - mod) % 2 != 0) x++;
    return x;
}
int ID(int L, int mod) {
    return mod == 0 ? L / 2 : (L + 1) / 2;
}


class SegmentTree {
private:
    vector<long long> sum;
    vector<int> cnt, lazy;
    int n;

    void remove(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return;
        if (lazy[i]) return;
        if (u <= l && r <= v) {
            sum[i] = cnt[i] = 0;
            lazy[i] = 1;
            return;
        }

        int m = (l + r) >> 1;
        remove(2 * i, l, m, u, v);
        remove(2 * i + 1, m + 1, r, u, v);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
    }

    pair<int, long long> get(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return make_pair(0, 0);
        if (lazy[i]) return make_pair(0, 0);
        if (u <= l && r <= v) return make_pair(cnt[i], sum[i]);

        int m = (l + r) >> 1;
        pair<int, long long> L = get(2 * i, l, m, u, v);
        pair<int, long long> R = get(2 * i + 1, m + 1, r, u, v);
        return L + R;
    }

    void build(int i, int l, int r, bool type) {
        if (l == r) {
            sum[i] = type == 0 ? 2 * r : 2 * r - 1;
            cnt[i] = 1;
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m, type);
        build(2 * i + 1, m + 1, r, type);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
    }

public:
    SegmentTree(int n = 0, bool type = 0) {
        this->n = n;
        sum.assign(4 * n + 7, 0);
        cnt.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);

        if (n > 0) build(1, 1, n, type);
    }

    void remove(int l, int r, bool type) {
        //printf("%s remove from %d to %d. ", type ? "Odd" : "Even", l, r);
        l = ID(next(l, type), type);
        r = ID(prev(r, type), type);
        //printf("Index from %d to %d\n", l, r);
        remove(1, 1, n, l, r);
    }

    pair<int, long long> get(int l, int r, bool type) const {
        //printf("%s get from %d to %d. ", type ? "Odd" : "Even", l, r);
        l = ID(next(l, type), type);
        r = ID(prev(r, type), type);
        //printf("Index from %d to %d. Result = %d and %lld\n", l, r, get(1, 1, n, l, r).fi, get(1, 1, n, l, r).se);
        return get(1, 1, n, l, r);
    }
};

#define MAX   300300

vector<int> segAt[MAX];
int minRight[MAX][2], maxRight[MAX][2];
int numSeg, length;

long long totSeg[MAX];

void init(void) {
    scanf("%d%d", &numSeg, &length);
    REP(pmp, numSeg) {
        int l, r; scanf("%d%d", &l, &r);
        segAt[l].push_back(r);
    }
}

void prepare(void) {
    memset(maxRight, -1, sizeof maxRight);

    FOR(i, 1, length) {
        REP(j, 2) maxRight[i][j] = maxRight[i - 1][j];

        FORE(jt, segAt[i]) maximize(maxRight[i][*jt % 2], *jt);
    }

    priority_queue<int, vector<int>, greater<int> > q[2];
    FOR(i, 1, length) {
        FORE(jt, segAt[i]) q[*jt % 2].push(*jt);
        REP(j, 2) {
            while (!q[j].empty() && q[j].top() < i) q[j].pop();
            minRight[i][j] = q[j].empty() ? MAX : q[j].top();
        }
    }

    FOR(i, 1, length) totSeg[i] = totSeg[i - 1] + 1LL * i * (i + 1) / 2;
}

void process(void) {
    long long res = 0;

    SegmentTree myit[2];
    myit[0] = SegmentTree(length / 2, 0);
    myit[1] = SegmentTree((length + 1) / 2, 1);

    FORD(L, length, 1) {
        pair<int, long long> toAdd;

        if (minRight[L][1 - L % 2] <= length) {
            int lim = minRight[L][1 - L % 2];
            //printf("Strict range of %d is %d\n", L, lim);
            toAdd = myit[L % 2].get(L, lim, L % 2);
        } else {
            int lim = maxRight[L][L % 2] + 1;
            maximize(lim, L);
            //printf("Free range of %d is %d\n", L, lim);

            toAdd = myit[L % 2].get(L, lim - 1, L % 2);
            REP(i, 2) toAdd = toAdd + myit[i].get(lim, length, i);
        }

        res += toAdd.se - 1LL * toAdd.fi * (L - 1);
        //long long tmp = toAdd.se - 1LL * toAdd.fi * (L - 1);
        //cout << tmp << " ";

        FORE(it, segAt[L]) {
            int u = L, v = *it;
            myit[1 - u % 2].remove(u, v, 1 - u % 2);
            if ((v - u + 1) % 2 == 0) REP(i, 2) myit[i].remove(v + 1, length, i);
        }
    }        

    vector<pair<int, int> > join;
    FOR(i, 1, length) FORE(jt, segAt[i]) {
        int L = i, R = *jt;
        if (join.empty() || L > join.back().se + 1) join.push_back(make_pair(L, R));
        else maximize(join.back().se, R);
    }

    if (join.front().fi > 1) res -= totSeg[join.front().fi - 1];
    if (join.back().se < length) res -= totSeg[length - join.back().se];

    REP(i, (int)join.size() - 1) if (join[i + 1].fi > join[i].se + 1)
        res -= totSeg[join[i + 1].fi - join[i].se - 1];

    cout << res << endl;
}

int main(void) {	
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/