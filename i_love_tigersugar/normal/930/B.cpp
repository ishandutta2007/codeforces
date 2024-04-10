#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   5050

int cnt[26][MAX][26], cntStr[26];

double solve(string s) {
    memset(cnt, 0, sizeof cnt);
    memset(cntStr, 0, sizeof cntStr);

    int n = s.size();
    FORE(it, s) cntStr[*it - 'a']++;
    REP(i, n) REP(j, n) cnt[s[i] - 'a'][j][s[(i + j) % n] - 'a']++;

    int res = 0;
    REP(i, 26) {
        int best = -1;
        REP(j, n) {
            int tmp = 0;
            REP(k, 26) if (cnt[i][j][k] == 1) tmp++;
            maximize(best, tmp);
        }
        res += best;
    }
    return 1.0 * res / n;
}

int main(void) {
    string s;
    while (cin >> s) printf("%.9lf\n", solve(s));
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/