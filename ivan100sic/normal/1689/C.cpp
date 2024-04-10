// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

vector<int> e[300005];
int n;
int dp[300005], sz[300005];

void dfs(int x, int p) {
    sz[x] = 1;
    int v1 = -1, v2 = -1;
    int y1 = -1, y2 = -1;
    for (int y : e[x]) {
        if (y == p) continue;
        dfs(y, x);
        sz[x] += sz[y];
        if (v1 == -1) {
            v1 = dp[y];
            y1 = y;
        } else {
            v2 = dp[y];
            y2 = y;
        }
    }

    if (v1 == -1) {
        dp[x] = 0;
    } else if (v2 == -1) {
        dp[x] = sz[x] - 2;
    } else {
        dp[x] = max(sz[y1]-1 + v2, sz[y2]-1 + v1);
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i : ra(0, n)) {
            e[i] = {};
        }

        for (int i : ra(1, n)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        dfs(0, 0);

        cout << dp[0] << '\n';
    }
}