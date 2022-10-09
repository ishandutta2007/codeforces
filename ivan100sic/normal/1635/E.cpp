// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
vector<pair<int, int>> e[200005];
int pos[200005], posx;
char c[200005], v[200005];
bool dfs_ok;

void dfs1(int x, char b) {
    if (c[x] && c[x] != b) {
        dfs_ok = 0;
        return;
    } else if (c[x]) {
        return;
    }

    c[x] = b;
    for (auto [y, _t] : e[x]) {
        dfs1(y, b ^ 'L' ^ 'R');
    }
}

void dfs2(int x) {
    v[x] = 1;
    for (auto [y, t] : e[x]) {
        if ((c[x] == 'L') == (t == 2) && !v[y]) {
            dfs2(y);
        }
    }
    pos[x] = ++posx;
}

void no() {
    cout << "NO\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;

    for (int i : ra(0, m)) {
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;
        e[x].emplace_back(y, t);
        e[y].emplace_back(x, t);
    }

    dfs_ok = 1;
    for (int x : ra(0, n)) {
        if (!c[x]) {
            dfs1(x, 'L');
        }
    }

    if (!dfs_ok) {
        no();
    }

    for (int x : ra(0, n)) {
        if (!v[x]) {
            dfs2(x);
        }
    }

    bool ord_ok = 1;
    for (int x : ra(0, n)) {
        for (auto [y, t] : e[x]) {
            if ((c[x] == 'L') ^ (pos[x] < pos[y]) ^ (t == 2)) {
                ord_ok = 0;
            }
        }
    }

    if (!ord_ok) {
        no();
    }

    cout << "YES\n";
    for (int x : ra(0, n)) {
        cout << c[x] << ' ' << pos[x] << '\n';
    }
}