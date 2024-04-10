#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   2020
const long long INF = (long long)1e18 + 7;
const int VALUE = (int)1e6;
int a[MAX], n, sum[MAX];

long long rightAnswer(void) {
    sum[0] = a[0];
    FOR(i, 1, n - 1) sum[i] = sum[i - 1] + a[i];
    long long res = -INF;
    REP(i, n) FOR(j, i, n - 1) {
        int tmp = i == 0 ? sum[j] : sum[j] - sum[i - 1];
        maximize(res, 1LL * (j - i + 1) * tmp);
    }
    return res;
}

long long wrongAnswer(void) {
    long long res = 0;
    int cur = 0, k = -1;
    REP(i, n) {
        cur += a[i];
        if (cur < 0) {
            cur = 0; k = i;
        }
        maximize(res, 1LL * (i - k) * cur);
    }
    return res;
}

void solve(int k) {
    n = 3;
    while ((n + k) % 2 != 0 || VALUE * (n - 2) < (n + k) / 2) n++;
//    cerr << n << endl;
    int s = (n + k) / 2;
    a[0] = 0;
    a[1] = -1;
    FOR(i, 2, n - 1) {
        a[i] = min(s, VALUE);
        s -= a[i];
    }

    long long jury = rightAnswer();
    long long cont = wrongAnswer();
//    cerr << jury << " " << cont << endl;
//    assert(jury - cont == k);

    printf("%d\n", n);
    REP(i, n) printf("%d ", a[i]); printf("\n");
}

int main(void) {
    int k;
    while (cin >> k) solve(k);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/