#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int n = 1 << k;
    vector<vector<long long>> a(n, vector<long long>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    int m;
    cin >> m;
    vector<pair<int, int>> f(m);
    for (int i = 0; i < m; ++i)
        cin >> f[i].first >> f[i].second;
    for (int i = m - 1; i >= 0; --i) {
        f[i].first = (f[i].first - f[0].first) & (n - 1);
        f[i].second = (f[i].second - f[0].second) & (n - 1);
    }
    for (int t = 0; t < k; ++t) {
        vector<vector<long long>> b(n, vector<long long>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (auto [x, y] : f)
                    b[(i + x) & (n - 1)][(j + y) & (n - 1)] ^= a[i][j];
        a = b;
        for (auto &[x, y] : f) {
            x = (2 * x) & (n - 1);
            y = (2 * y) & (n - 1);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] > 0)
                ++cnt;
    cout << cnt << "\n";
    return 0;
}