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
pair<int, int> res[MAX];

void process(void) {
    int n, q; cin >> n >> q;
    int maxValue = 0;
    deque<int> dq;
    REP(love, n) {
        int x; cin >> x;
        maximize(maxValue, x);
        dq.push_back(x);
    }

    int numStep = 0;
    while (dq.front() < maxValue) {
        numStep++;
        int a = dq.front(); dq.pop_front();
        int b = dq.front(); dq.pop_front();
        res[numStep] = make_pair(a, b);
        dq.push_front(max(a, b));
        dq.push_back(min(a, b));
    }
    vector<int> values;
    dq.pop_front();
    while (!dq.empty()) {
        values.push_back(dq.front()); dq.pop_front();
    }

    REP(love, q) {
        long long step; cin >> step;
        if (step <= numStep) cout << res[step].fi << " " << res[step].se << "\n";
        else {
            step -= numStep + 1;
            cout << maxValue << " " << values[step % values.size()] << "\n";
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/