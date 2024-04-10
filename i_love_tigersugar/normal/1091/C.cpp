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

vector<int> divisors(int x) {
    vector<int> res;
    for (int i = 1; 1LL * i * i <= x; i++) if (x % i == 0) {
        res.push_back(i);
        if (i != x / i) res.push_back(x / i);
    }
    return res;
}

long long getSum(int n, int d) {
    return 1LL * n * (n / d - 1) / 2 + n / d;
}

void solve(int n) {
    set<long long> s;
    vector<int> div = divisors(n);
    FORE(it, div) s.insert(getSum(n, *it));

    FORE(it, s) cout << *it << " "; cout << endl;
}

int main(void) {
    int n; while (cin >> n) solve(n);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/