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

struct SetWithSum {
    multiset<int> s;
    long long sum;

    SetWithSum() {
        sum = 0;
    }

    void insert(int x) {
        s.insert(x);
        sum += x;
    }

    long long getSum(void) const {
        return sum;
    }

    void pop(void) {
        __typeof(s.begin()) it = s.end(); it--;
        sum -= *it;
        s.erase(it);
    }

    void clear(void) {
        sum = 0;
        s.clear();
    }

    int size(void) const {
        return s.size();
    }
};

#define MAX   200200
map<int, vector<int>> values;
int n, cur[MAX], cost[MAX];

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &cur[i]);
    FOR(i, 1, n) scanf("%d", &cost[i]);
    FOR(i, 1, n) values[cur[i]].push_back(cost[i]);

    SetWithSum s;
    int t = 0;
    long long res = 0;
    while (true) {
        __typeof(values.begin()) it = values.find(t);
        if (it != values.end()) {
            FORE(jt, it->se) s.insert(*jt);
        }
        if (s.size() < 2) {
            s.clear();
            it = values.upper_bound(t);
            if (it == values.end()) break;
            t = it->fi;
            continue;
        } else {
            s.pop();
            res += s.getSum();
            t++;
        }
    }

    cout << res << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/