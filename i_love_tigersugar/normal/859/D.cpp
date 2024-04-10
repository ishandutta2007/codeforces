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

#define MAX   7

double f[MASK(MAX) + 3][MAX + 3];
double win[MASK(MAX) + 3][MAX + 3];
double prob[MASK(MAX) + 3][MASK(MAX) + 3];
int n;

void init(void) {
    cin >> n;
    REP(i, MASK(n)) REP(j, MASK(n)) {
        int x; cin >> x;
        prob[i][j] = 1.0 * x / 100;
    }
}

bool canMeet(int x, int y, int lv) {
    if (lv < 1) return false;
    return ((x ^ y) >> (lv - 1)) == 1;
}

#define IS_NAN(x) (std::isnan(x))
double probWin(int team, int lv) {
    if (!IS_NAN(win[team][lv])) return win[team][lv];
    if (lv == 0) return 1.0;
    double res = 0.0;
    REP(other, MASK(n)) if (canMeet(team, other, lv))
        res += prob[team][other] * probWin(other, lv - 1);
    return win[team][lv] = res * probWin(team, lv - 1);
}
double dp(int team, int lv) {
    if (!IS_NAN(f[team][lv])) return f[team][lv];
    if (lv == 0) return 0;
    double res = -1;
    REP(other, MASK(n)) if (canMeet(team, other, lv)) {
        double prevScore = dp(team, lv - 1) + dp(other, lv - 1);
        double matchScore = probWin(team, lv) * MASK(lv - 1);
        maximize(res, prevScore + matchScore);
    }
    assert(res >= 0);
    return f[team][lv] = res;
}

void process(void) {
    memset(win, -1, sizeof win);
    memset(f, -1, sizeof f);
    assert(IS_NAN(f[0][0]) && IS_NAN(win[0][0]));
    double res = -1;
    REP(i, MASK(n)) maximize(res, dp(i, n));
    printf("%.12lf\n", res);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/