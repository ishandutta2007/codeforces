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

#define MAX   1000100
const int INF = (int)1e8 + 7;

bool notPrime[MAX];
vector<int> primeDiv[MAX];

void eratosthene(void) {
    REP(i, 2) notPrime[i] = true;
    FOR(i, 2, MAX - 1) if (!notPrime[i])
        for (int j = 2 * i; j < MAX; j += i) notPrime[j] = true;
    FOR(i, 1, MAX - 1) if (!notPrime[i])
        for (int j = i; j < MAX; j += i) primeDiv[j].push_back(i);
}

int countCoprime(int value, int limit) {
    int res = 0;
    vector<int> &primes = primeDiv[value];
    REP(mask, MASK(primes.size())) {
        int prod = 1;
        REP(i, primes.size()) if (BIT(mask, i)) prod *= primes[i];
        if (prod <= limit) {
            if (__builtin_popcount(mask) % 2 == 0) res += limit / prod;
            else res -= limit / prod;
        }
    }
    return res;
}

int solve(int limit, int value, int pos) {
    pos += countCoprime(value, limit);
    int L = limit;
    int R = INF;
    while (true) {
        if (L == R) return R;
        if (R - L == 1) return countCoprime(value, L) >= pos ? L : R;
        int M = (L + R) >> 1;
        if (countCoprime(value, M) >= pos) R = M; else L = M + 1;
    }
}

int main(void) {
    eratosthene();
    int t; scanf("%d", &t);
    REP(love, t) {
        int x, p, k; scanf("%d%d%d", &x, &p, &k);
        printf("%d\n", solve(x, p, k));
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/