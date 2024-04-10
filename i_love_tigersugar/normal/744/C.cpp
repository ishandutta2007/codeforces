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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   17
const int INF = (int)1e9 + 7;

pair<int, int> need[MAX];
int redMask, blueMask, n;
int maxBlue[MASK(MAX) + 3][MAX * MAX];

void init(void) {
    scanf("%d", &n);
    REP(i, n) {
        char s[3]; scanf("%s", s);
        int r, b; scanf("%d%d", &r, &b);
        if (s[0] == 'R') redMask |= MASK(i); else blueMask |= MASK(i);
        need[i] = make_pair(r, b);
    }
}

void process(void) {
    memset(maxBlue, -1, sizeof maxBlue);

    maxBlue[0][0] = 0;
    REP(i, MASK(n)) {
        int numRed = __builtin_popcount(i & redMask);
        int numBlue = __builtin_popcount(i & blueMask);
        REP(j, n * n + 1) if (maxBlue[i][j] >= 0)
            REP(k, n) if (!BIT(i, k)) {
                int red = j + min(need[k].fi, numRed);
                int blue = maxBlue[i][j] + min(need[k].se, numBlue);
                maximize(maxBlue[i | MASK(k)][red], blue);
            }
    }

    int res = INF;
    int sumRed = 0, sumBlue = 0;
    REP(i, n) {
        sumRed += need[i].fi;
        sumBlue += need[i].se;
    }
    REP(j, n * n + 1) if (maxBlue[MASK(n) - 1][j] >= 0) {
        int totRed = sumRed - j;
        int totBlue = sumBlue - maxBlue[MASK(n) - 1][j];
        minimize(res, max(totRed, totBlue));
    }

    printf("%d\n", res + n);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/