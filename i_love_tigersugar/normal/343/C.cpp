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

#define MAX   300300
const long long INF = (long long)1e13;

int numSource, numDest;
long long sources[MAX], dests[MAX];

void init(void) {
    cin >> numSource >> numDest;
    FOR(i, 1, numSource) cin >> sources[i];
    FOR(i, 1, numDest) cin >> dests[i];
    sort(sources + 1, sources + numSource + 1);
    sort(dests + 1, dests + numDest + 1);
}

bool ok(long long limit) {
    int did = 1;
    FOR(sid, 1, numSource) {
        if (did > numDest) return true;
        if (sources[sid] - dests[did] > limit) return false;

        long long range;
        if (sources[sid] <= dests[did]) range = sources[sid] + limit;
        else {
            range = sources[sid];
            maximize(range, limit + 2 * dests[did] - sources[sid]);
            maximize(range, (sources[sid] + dests[did] + limit) / 2);
        }

        while (did <= numDest && dests[did] <= range) did++;
    }
    return did > numDest;
}

long long process(void) {
    long long L = 0, R = INF;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return ok(L) ? L : R;
        long long M = (L + R) >> 1;
        if (ok(M)) R = M; else L = M + 1;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    init();
    cout << process() << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/