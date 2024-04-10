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

vector<pair<int, int>> sequences;
vector<int> maxValues, minValues;

void readSequence(void) {
    vector<int> v;
    int k; scanf("%d", &k);
    REP(love, k) {
        int x; scanf("%d", &x);
        v.push_back(x);
    }

    REP(i, k - 1) if (v[i] < v[i + 1]) return;
    sequences.push_back(make_pair(v.front(), v.back()));
}

void process(void) {
    int n; scanf("%d", &n);
    REP(love, n) readSequence();

    FORE(it, sequences) {
        maxValues.push_back(it->fi);
        minValues.push_back(it->se);
    }

    sort(ALL(maxValues));
    sort(ALL(minValues));

    long long numFail = 0;
    FORE(it, sequences) {
        int j;
        j = upper_bound(ALL(maxValues), it->se) - maxValues.begin();
        numFail += j;
    }

    cout << 1LL * n * n - numFail << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/