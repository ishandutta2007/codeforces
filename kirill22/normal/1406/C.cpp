#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

vector<vector<int>> g;
vector<int> sz;

void dfs(int v, int pr) {
    sz[v] = 1;
    for (auto x : g[v]) if (x != pr) {
        dfs(x, v);
        sz[v] += sz[x];
    }
}

void solve() {
    int n;
    cin >> n;
    g.clear();
    sz.clear();
    sz.resize(n);
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1);
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (auto j : g[i]) {
            if (n % 2 == 0 && sz[i] == n / 2 && sz[j] > sz[i]) x = i, y = j;
        }
    }
    if (x == -1 && y == -1) {
        for (int i = 0; i < n; i++) {
            for (auto j : g[i]) {
                cout << i + 1 << " " << j + 1 << '\n';
                cout << i + 1 << " " << j + 1 << '\n';
                return;
            }
        }
    }
    int z = -1;
    for (auto j : g[x]) if (j != y) z = j;
    cout << z + 1 << " " << x + 1 << '\n';
    cout << z + 1 << " " << y + 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}