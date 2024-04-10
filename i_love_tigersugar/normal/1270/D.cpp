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

int n, k;

pair<int, int> ask(const vector<int> &indices) {
    assert(indices.size() == k);
    cout << "?";
    FORE(it, indices) cout << " " << *it;
    cout << endl;

    int x, val; cin >> x >> val;
    return make_pair(x, val);
}

void answer(int x) {
    cout << "! " << x << endl;
    exit(EXIT_SUCCESS);
}

void process(void) {
    cin >> n >> k;
    vector<int> firstK;
    FOR(i, 1, k) firstK.push_back(i);

    pair<int, int> tmp = ask(firstK);
    int x = tmp.fi, ax = tmp.se;

    int numLeft = 0, numRight = 0, numSame = 0;
    FOR(i, 1, k) if (i != x) {
        vector<int> toAsk = firstK;
        FORE(jt, toAsk) if (*jt == i) *jt = k + 1;

        tmp = ask(toAsk);
        int y = tmp.fi, ay = tmp.se;
        if (x == y) numSame++;
        else {
            if (ax < ay) numLeft++;
            else numRight++;
        }
    }

    if (numLeft > 0) answer(numLeft + 1);
    if (numRight > 0) answer(numSame + 1);

    FORE(it, firstK) if (*it == x) *it = k + 1;
    tmp = ask(firstK);
    int y = tmp.fi, ay = tmp.se;
    answer(ay > ax ? 1 : k);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/