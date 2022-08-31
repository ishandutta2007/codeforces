#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; ++i)
        cin >> g[i];
    vector<vector<int>> sum(n + 1);
    for (int i = 0; i <= n; ++i)
        sum[i].resize(m + 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (g[i][j] == 'X');
    vector<vector<int>> a(n + 1);
    auto check = [&](int r) {
        int d = 2 * r + 1;
        for (int i = 0; i <= n; ++i)
            a[i].assign(m + 1, 0);
        for (int i = 0; i + d <= n; ++i) {
            for (int j = 0; j + d <= m; ++j) {
                if (sum[i + d][j + d] - sum[i + d][j] - sum[i][j + d] + sum[i][j] == d * d) {
                    ++a[i][j];
                    --a[i][j + d];
                    --a[i + d][j];
                    ++a[i + d][j + d];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0)
                    a[i][j] += a[i - 1][j];
                if (j > 0)
                    a[i][j] += a[i][j - 1];
                if (i > 0 && j > 0)
                    a[i][j] -= a[i - 1][j - 1];
                if (g[i][j] == 'X' && a[i][j] == 0)
                    return false;
            }
        }
        return true;
    };
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << "\n";
    int d = 2 * l + 1;
    for (int i = 0; i < n; ++i, cout << "\n")
        for (int j = 0; j < m; ++j)
            cout << ".X"[i >= l && i + l < n && j >= l && j + l < m && sum[i + l + 1][j + l + 1] - sum[i + l + 1][j - l] - sum[i - l][j + l + 1] + sum[i - l][j - l] == d * d];
    return 0;
}