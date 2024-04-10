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

vector<long long> getSequence(int length, long long value, long long range) {
    if (length == 0) return vector<long long>(1, value);

    vector<long long> res;
    REP(love, length - 1) res.push_back(value);
    res.push_back(value + range - 1);
    res.push_back(value + 2 * range - 1);
    return res;
}

void solve(int numSet, int range) {
    vector<long long> res;
    REP(i, 30) if (BIT(numSet, i)) {
        vector<long long> seq = getSequence(i, res.empty() ? 1 : res.back() + 2 * range, range);
        FORE(it, seq) res.push_back(*it);
    }
    cout << res.size() << endl;
    FORE(it, res) cout << *it << " "; cout << endl;
}

int main(void) {
    int x, d; while (cin >> x >> d) solve(x, d);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/