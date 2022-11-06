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

void dfs(vector<vector<int>> &e, vector<int> &u, int i) {
    if (u[i]) return;
    u[i] = 1;
    for (int j : e[i]) dfs(e, u, j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    forn(i, 0, n) {
        int j;
        cin >> j;
        --j;
        e[i].eb(j);
        e[j].eb(i);
    }
    vector<int> u(n);
    int cnt = 0;
    forn(i, 0, n) {
        if (!u[i]) ++cnt;
        dfs(e, u, i);
    }
    cout << cnt << '\n';
}