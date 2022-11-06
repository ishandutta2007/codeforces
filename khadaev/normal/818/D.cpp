#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

struct Set {
    set<pair<int, int>> by_color, by_cnt;
    int cntA = 0;

    Set () {
        cntA = 0;
    };

    void add(int c) {
        auto it = by_color.lower_bound({c, -1});
        if (it == by_color.end() || it->fs != c) {
            if (cntA) return;
            by_color.emplace(c, 1);
            by_cnt.emplace(1, c);
        } else {
            int cnt = it->second;
            by_color.erase(it);
            by_cnt.erase({cnt, c});
            by_color.emplace(c, cnt + 1);
            by_cnt.emplace(cnt + 1, c);
        }
    }

    void eraseLess() {
        while (!by_cnt.empty() && by_cnt.begin()->fs < cntA) {
            auto it = by_cnt.begin();
            int x = it->fs, y = it->sn;
            by_cnt.erase(it);
            by_color.erase({y, x});
        }
    }

    int getAns() {
        if (by_color.empty()) return -1;
        return by_color.begin()->fs;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, A;
    cin >> n >> A;
    Set S;
    while (n--) {
        int c;
        cin >> c;
        if (c == A) {
            ++S.cntA;
            S.eraseLess();
        } else {
            S.add(c);
        }
    }
    cout << S.getAns() << '\n';
}