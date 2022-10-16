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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE.  **/

#define MAX   5050
bool same[MAX], palin[MAX][MAX];
char input[MAX];
int n;

bool ok(int l, int r) {
    if (l + r > n) return false;
    int pl = min(l, r);
    if (pl > 0 && !same[pl]) return false;
    if (l > r && !palin[r + 1][l]) return false;
    if (r > l && !palin[n - r + 1][n - l]) return false;
    return true;
}

string solve(const string &s) {
    n = s.size();
    FOR(i, 1, n) input[i] = s[i - 1];

    FOR(i, 1, n) same[i] = false;
    FOR(i, 1, n) FOR(j, 1, n) palin[i][j] = false;

    same[0] = true;
    FOR(i, 1, n / 2) same[i] = same[i - 1] && (input[i] == input[n - i + 1]);

    FOR(i, 1, n) palin[i][i] = true;
    FOR(i, 1, n - 1) palin[i][i + 1] = input[i] == input[i + 1];

    FOR(d, 2, n) FOR(i, 1, n - d) {
        int j = i + d;
        palin[i][j] = palin[i + 1][j - 1] && (input[i] == input[j]);
    }

    pair<int, int> best(-1, -1);
    FOR(i, 0, n) FOR(j, 0, n) if (ok(i, j) && i + j > best.fi + best.se) best = make_pair(i, j);

    string res;
    FOR(i, 1, best.fi) res.push_back(input[i]);
    FOR(i, n - best.se + 1, n) res.push_back(input[i]);
    return res;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    REP(love, t) {
        string s; cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/