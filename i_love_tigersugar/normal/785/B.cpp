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

#define MAX   500500
#define MAGIC   1000

pair<int, int> a[MAX], b[MAX];
int m, n;

void init(void) {
    scanf("%d", &m);
    REP(i, m) scanf("%d%d", &a[i].fi, &a[i].se);
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", &b[i].fi, &b[i].se);
}

bool compFirst(const pair<int, int> &a, const pair<int, int> &b) {
    return a.fi < b.fi;
}
bool compSecond(const pair<int, int> &a, const pair<int, int> &b) {
    return a.se < b.se;
}

int calc(const pair<int, int> &a, const pair<int, int> &b) {
    return max(0, max(a.fi, b.fi) - min(a.se, b.se));
}

void process(void) {
    vector<pair<int, int> > canA, canB;

    REP(love, 2) {
        sort(a, a + m, love ? compFirst : compSecond);
        REP(i, min(m, MAGIC)) {
            canA.push_back(a[i]);
            canA.push_back(a[m - 1 - i]);
        }
    }

    REP(love, 2) {
        sort(b, b + n, love ? compFirst : compSecond);
        REP(i, min(n, MAGIC)) {
            canB.push_back(b[i]);
            canB.push_back(b[n - 1 - i]);
        }
    }

    sort(ALL(canA)); canA.resize(unique(ALL(canA)) - canA.begin());
    sort(ALL(canB)); canB.resize(unique(ALL(canB)) - canB.begin());

    int best = 0;
    FORE(it, canA) FORE(jt, canB) maximize(best, calc(*it, *jt));
    printf("%d\n", best);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/