#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

vector<pair<int, int>> ans;
set<int> rest;

void add(int x, int y) {
    assert(__gcd(x, y) != 1);
    assert(rest.count(x));
    assert(rest.count(y));
    rest.erase(x);
    rest.erase(y);
    ans.eb(x, y);
}

void solve(int n) {
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    fore(i, 1, n) rest.insert(i);
    vector<int> p(n + 1);
    fore(i, 0, n) p[i] = i;
    fore(i, 2, n)
        if (p[i] == i)
            for (int j = i; j <= n; j += i)
                p[j] = i;
    vector<vector<int>> d(n + 1);
    fore(i, 2, n)
        d[p[i]].eb(i);
    fore(i, 3, n) {
        if (d[i].size() < 2) continue;
        if (d[i].size() % 2) {
            add(d[i][0], d[i][2]);
            d[2].eb(d[i][1]);
        }
        int j = d[i].size() % 2 ? 3 : 0;
        for (; j < (int)d[i].size(); j += 2)
            add(d[i][j], d[i][j + 1]);
    }
    for (int j = 0; j + 1 < (int)d[2].size(); j += 2)
        add(d[2][j], d[2][j + 1]);
    cout << ans.size() << '\n';
    for (auto q : ans) cout << q.fs << ' ' << q.sn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
}