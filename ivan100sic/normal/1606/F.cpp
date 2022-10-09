// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
vector<vector<int>> e, dp, dp_out;
vector<int> ch;

void vadd(vector<int>& a, int i, int x) {
    while (i >= ssize(a)) {
        a.emplace_back(0);
    }

    a[i] += x;
}

void dfs(int x, int p) {
    ch[x] = ssize(e[x]) - (x != 1);
    int h = ch[x] + 1;
    for (int y : e[x]) {
        if (y == p) continue;
        dfs(y, x);
        h = max(h, (int)ssize(dp[y]));
    }

    vector<int> lz(h+1);
    dp[x].resize(h);

    for (int y : e[x]) {
        if (y == p) continue;
        for (int i : ra(0, ssize(dp[y]))) {
            dp[x][i] += max(1, dp[y][i] - i);
        }
        lz[ssize(dp[y])] += 1;
    }

    for (int i : ra(0, h)) {
        if (i) lz[i] += lz[i-1];
        dp[x][i] += lz[i];
    }

    dp_out[x] = dp[x];

    while (1) {
        int i = ssize(dp[x]) - 1;
        if (i >= 0 && dp[x][i] - i <= 1) {
            dp[x].pop_back();
        } else {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    e.resize(n+1);
    dp.resize(n+1);
    dp_out.resize(n+1);
    ch.resize(n+1);
    for (int i : ra(1, n)) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs(1, 1);

    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;
        if (k < ssize(dp_out[x])) {
            cout << dp_out[x][k] << '\n';
        } else {
            cout << ch[x] << '\n';
        }
    }
}