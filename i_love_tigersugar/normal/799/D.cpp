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

const int INF = (int)1e9 + 7;

vector<pair<int, int> > values;

int a, b, h, w, best;

void init(void) {
    map<int, int> cnt;

    int n; scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
    REP(pmp, n) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }

    FORE(it, cnt) values.push_back(*it);
    reverse(ALL(values));
}

void backtrack(int curA, int goalA, int curB, int goalB, int pos, int sum) {
    if (curA >= goalA && curB >= goalB) return minimize(best, sum);
    if (sum >= best || pos >= values.size()) return;

    REP(useA, values[pos].se + 1) {
        if (sum + useA >= best) break;

        int tmpB = curB;
        REP(useB, values[pos].se - useA + 1) {
            if (sum + useA + useB >= best) break;
            backtrack(curA, goalA, tmpB, goalB, pos + 1, sum + useA + useB);

            if (tmpB >= goalB) break;
            tmpB = min(1LL * tmpB * values[pos].fi, 1LL * INF);
        }

        if (curA >= goalA) break;
        curA = min(1LL * curA * values[pos].fi, 1LL * INF);
    }
}

void process(void) {
    best = INF;
    backtrack(w, a, h, b, 0, 0);
    backtrack(w, b, h, a, 0, 0);

    printf("%d\n", best < INF ? best : -1);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/