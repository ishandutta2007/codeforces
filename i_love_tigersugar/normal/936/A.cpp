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

const long long INF = (long long)4e18 + 7LL;

long long calcPart(long long off, long long check, long long time) {
    bool odd = time % 2 == 1;
    time /= 2;

    long long block = off % check == 0 ? off : off + check - off % check;
    long long give = off * 2 + block - off;

    long long res = (time / block) * give;
    time %= block;
    res += min(off, time) * 2;
    if (time > off) res += time - off;
    if (time < off && odd) res++;
    return res;
}

long long solve(long long off, long long check, long long need) {
    long long L = 0, R = INF;

    while (true) {
        if (L == R) return L;
        if (R - L == 1) return calcPart(off, check, L) >= 2 * need ? L : R;
        long long M = (L + R) >> 1;
        if (calcPart(off, check, M) >= 2 * need) R = M; else L = M + 1;
    }
}

int main(void) {
    long long off, check, need;
    while (cin >> off >> check >> need)
        printf("%.3lf\n", solve(off, check, need) * 0.5);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/