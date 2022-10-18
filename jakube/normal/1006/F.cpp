#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    long long k;
    cin >> k;
    vector<vector<long long>> v(min(n, m), vector<long long>(max(n, m)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (n <= m)
                cin >> v[i][j];
            else
                cin >> v[j][i];
        }
    }

    if (n > m)
        swap(n, m);

    using mll = map<long long, long long>;
    using vmll = vector<mll>;
    using vvmll = vector<vmll>;
    vvmll maps(n, vmll(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - 1 - i; j++) {
            if (i == 0 && j == 0) {
                maps[i][j][v[i][j]] = 1;
            }
            if (i) {
                for (auto [xors, cnt] : maps[i-1][j])
                    maps[i][j][xors ^ v[i][j]] += cnt;
            }
            if (j) {
                for (auto [xors, cnt] : maps[i][j-1])
                    maps[i][j][xors ^ v[i][j]] += cnt;
            }
        }
    }

    vvmll maps2(n, vmll(m));
    for (int i = n-1; i >= 0; i--) {
        for (int j = m - 1; j >= n - 1 - i; j--) {
            if (i == n-1 && j == m-1) {
                maps2[i][j][v[i][j]] = 1;
            }
            if (i < n - 1) {
                for (auto [xors, cnt] : maps2[i+1][j])
                    maps2[i][j][xors ^ v[i][j]] += cnt;
            }
            if (j < m - 1) {
                for (auto [xors, cnt] : maps2[i][j+1])
                    maps2[i][j][xors ^ v[i][j]] += cnt;
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (auto [xors, cnt] : maps[i][n-1-i]) {
            res += cnt * maps2[i][n-1-i][xors ^ v[i][n-1-i] ^ k];
        }
    }
    cout << res << '\n';
}