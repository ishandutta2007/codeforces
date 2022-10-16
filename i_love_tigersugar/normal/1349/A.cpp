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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

long long pw(int x, int k) {
    long long res = 1, mul = x;
    while (k > 0) {
        if (k & 1) res *= mul;
        mul *= mul;
        k >>= 1;
    }
    return res;
}

#define MAX   500500
vector<int> muls[MAX];

void getPrimeFact(int x) {
    for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) {
        int j = 0;
        while (x % i == 0) {
            x /= i; j++;
        }
        muls[i].push_back(j);
    }

    if (x > 1) muls[x].push_back(1);
}

void process(void) {
    int n; scanf("%d", &n);
    REP(love, n) {
        int x; scanf("%d", &x); getPrimeFact(x);
    }

    long long res = 1;
    REP(i, MAX) if (muls[i].size() > n - 2) {
        vector<int> &v = muls[i];
        sort(ALL(v));
        res *= pw(i, v[v.size() - n + 1]);
    }
    cout << res << endl;
}

int main(void) {
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/