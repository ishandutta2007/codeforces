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

#define MAX  300300

int n, k;
string input;
int value[MAX];

long long getSegment(int l, int r) {
    priority_queue<int, vector<int>, greater<int>> q;
    FOR(i, l, r) q.push(value[i]);
    while (q.size() > k) q.pop();
    long long sum = 0;
    while (!q.empty()) {
        sum += q.top(); q.pop();
    }
    return sum;
}

void process(void) {
    cin >> n >> k;
    REP(i, n) cin >> value[i];
    cin >> input;

    long long sum = 0;
    vector<int> pos(1, 0);
    FOR(i, 1, n - 1) if (input[i] != input[i - 1]) pos.push_back(i);
    pos.push_back(n);
    REP(i, pos.size() - 1) sum += getSegment(pos[i], pos[i + 1] - 1);

    cout << sum << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/