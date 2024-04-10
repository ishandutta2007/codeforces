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

class DisjointSet {
private:
    vector<int> lab;

    int find(int x) {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

public:
    DisjointSet(int n = 0) {
        lab.assign(n + 7, -1);
    }

    bool join(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

long long n;
vector<long long> getPrimeFacts(long long n) {
    set<long long> s;
    for (int i = 2; 1LL * i * i <= n; i++) if (n % i == 0) {
        s.insert(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) s.insert(n);
    return vector<long long>(ALL(s));
}

long long solve(long long n) {
    if (n == 1) return 1;
    vector<long long> primeFacts = getPrimeFacts(n);
    if (primeFacts.size() == 1 && primeFacts[0] == n) return n;

    sort(ALL(primeFacts));
    int minFact = primeFacts[0];

    DisjointSet dsu(minFact);
    int numComp = minFact;
    FOR(i, 1, (int)primeFacts.size() - 1) {
        long long j = primeFacts[i];
        REP(k, minFact) {
            if (dsu.join(k, (k + j) % minFact)) numComp--;
        }
    }

    return numComp;
}

int main(void) {
    long long n;
    while (cin >> n) cout << solve(n) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/