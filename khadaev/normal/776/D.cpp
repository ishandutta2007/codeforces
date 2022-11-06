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

void fail() {
    cout << "NO\n";
    exit(0);

}

int m;
vector<int> ans;
vector<vector<pair<int, int>>> e;


void dfs(int i, int val) {
    if (ans[i] == val) return;
    if (ans[i] != -1) fail();
    ans[i] = val;
    for (auto p : e[i]) {
        int j = p.fs, r = p.sn;
        dfs(j, r ? 1 - val : val);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> m;
    e.resize(m);
    vector<int> r(n);
    forn(i, 0, n) {
        cin >> r[i];
        r[i] = 1 - r[i];
    }
    vector<vector<int>> q(n);
    forn(i, 0, m) {
        int x;
        cin >> x;
        while (x--) {
            int rm;
            cin >> rm;
            --rm;
            q[rm].eb(i);
        }
    }
    forn(i, 0, n) assert(q[i].size() == 2);
    forn(i, 0, n) {
        int u = q[i][0], v = q[i][1];
        e[u].eb(v, r[i]);
        e[v].eb(u, r[i]);
    }
    ans = vector<int> (m, -1);
    forn(i, 0, m) if (ans[i] == -1) dfs(i, 0);
    cout << "YES\n";
}