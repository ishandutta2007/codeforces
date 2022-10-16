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

#define MAX   100100
map<vector<pair<int, int>>, int> cnt;
int mod;

vector<pair<int, int>> getPrime(int x) {
    map<int, int> cnt;
    for (int i = 2; 1LL * i * i <= x; i++) {
        while (x % i == 0) {
            cnt[i]++; x /= i;
        }
    }
    if (x > 1) cnt[x]++;

    vector<pair<int, int>> res;
    FORE(it, cnt) if (it->se % mod != 0) res.push_back(make_pair(it->fi, it->se % mod));
    return res;
}

void process(void) {
    int n; scanf("%d%d", &n, &mod);
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        cnt[getPrime(x)]++;
    }

    long long res = 0;
    FORE(it, cnt) {
        const vector<pair<int, int>> &cur = it->fi;
        vector<pair<int, int>> need;
        FORE(jt, cur) need.push_back(make_pair(jt->fi, mod - jt->se));
        if (cur == need) res += 1LL * it->se * (it->se - 1);
        else {
            __typeof(cnt.begin()) kt = cnt.find(need);
            if (kt == cnt.end()) continue;
            res += 1LL * it->se * kt->se;
        }
    }

    cout << res / 2 << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/