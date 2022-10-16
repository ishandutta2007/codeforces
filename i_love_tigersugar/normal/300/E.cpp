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

#define MAX_SIZE   1000100
#define MAX_VALUE   10001000
const long long INF = (long long)1e13 + 7LL;

int primeDiv[MAX_VALUE], values[MAX_SIZE], n;
vector<int> primes;
long long totExp[MAX_VALUE];

void eratosthene(void) {
    REP(i, 2) primeDiv[i] = -1;
    for (int i = 2; 1LL * i * i < MAX_VALUE; i++) if (primeDiv[i] == 0) {
        primes.push_back(i);
        primeDiv[i] = i;
        for (int j = i * i; j < MAX_VALUE; j += i) primeDiv[j] = i;
    }

    FOR(i, 2, MAX_VALUE - 1) if (primeDiv[i] == 0) {
        primeDiv[i] = i;
        primes.push_back(i);
    }
}

void addExp(int val, int mul) {
    while (val > 1) {
        totExp[primeDiv[val]] += mul;
        val /= primeDiv[val];
    }
}

bool ok(long long n) {
    FORE(it, primes) {
        long long pw = *it;
        long long sum = totExp[*it];
        while (sum > 0) {
            sum -= n / pw;
            if (1LL * pw * (*it) > n) break;
            pw *= *it;
        }
        if (sum > 0) return false;
    }
    return true;
}

long long process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &values[i]);
    sort(values + 1, values + n + 1);
    FOR(i, 1, n) FOR(j, values[i - 1] + 1, values[i]) addExp(j, n - i + 1);

    long long L = 1, R = INF;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return ok(L) ? L : R;
        long long M = (L + R) >> 1;
        if (ok(M)) R = M; else L = M + 1;
    }
}

int main(void) {
#ifdef ONLINE_JUDGE
//    freopen("factorial.inp", "r", stdin);
//    freopen("factorial.out", "w", stdout);
#endif // ONLINE_JUDGE
    eratosthene();
    cout << process() << endl;
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/