#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k;
    cin >> k;
    vector<vector<int>> a(k), cir(k);
    vector<vector<pair<int, int>>> to(k);
    vector<int64> sum(k);
    int64 need = 0;
    map<int64, pair<int, int>> pos;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        a[i].resize(n);
        cir[i].resize(n);
        to[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            need += a[i][j];
            pos[a[i][j]] = {i, j};
            sum[i] += a[i][j];
        }
    }
    if (need % k != 0) {
        cout << "No" << endl;
        return 0;
    }
    need /= k;
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < (int)a[i].size(); ++j)
            to[i][j] = pos.count(need - sum[i] + a[i][j])
                           ? pos[need - sum[i] + a[i][j]]
                           : make_pair(-1, -1);
    vector<bool> can(1 << k);
    vector<int> g(1 << k, -1);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (int)a[i].size(); ++j) {
            int x = i, y = j, s = 1 << i;
            bool ok = false;
            while (true) {
                if (to[x][y].first == -1) break;
                tie(x, y) = to[x][y];
                if (x == i && y == j) {
                    ok = true;
                    break;
                }
                if (s >> x & 1) break;
                s |= 1 << x;
            }
            if (ok) {
                cir[i][j] = s;
                can[s] = true;
            }
        }
    }
    for (int i = 1; i < (1 << k); ++i) {
        if (!can[i]) {
            for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                if (can[j] && can[i ^ j]) {
                    can[i] = true;
                    g[i] = j;
                    break;
                }
            }
        }
    }
    if (!can[(1 << k) - 1]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<int> w(k), t(k);
    function<void(int)> dfs = [&](int s) {
        if (g[s] == -1) {
            int i = 0;
            while (~s >> i & 1) ++i;
            for (int j = 0; j < (int)a[i].size(); ++j) {
                if (cir[i][j] == s) {
                    int x = i, y = j;
                    while (true) {
                        w[x] = y;
                        t[to[x][y].first] = x;
                        tie(x, y) = to[x][y];
                        if (x == i) break;
                    }
                }
            }
        } else {
            dfs(g[s]);
            dfs(s ^ g[s]);
        }
    };
    dfs((1 << k) - 1);
    for (int i = 0; i < k; ++i) cout << a[i][w[i]] << " " << t[i] + 1 << endl;
    return 0;
}