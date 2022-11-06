#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A, Lmin, Lmax, Rmin, Rmax;
    A = Lmax = Rmax = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
    Lmin = Rmin = vector<vector<int>>(n + 2, vector<int>(m + 2, 1e6 + 5));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            Lmin[i][j] = min(Lmin[i][j - 1], A[i][j]);
            Lmax[i][j] = max(Lmax[i][j - 1], A[i][j]);
        }
        for (int j = m; j >= 1; --j) {
            Rmin[i][j] = min(Rmin[i][j + 1], A[i][j]);
            Rmax[i][j] = max(Rmax[i][j + 1], A[i][j]);
        }
    }
    for (int k = 1; k < m; ++k) {
        vector<int> L;
        for (int i = 1; i <= n; ++i) L.push_back(i);
        sort(L.begin(), L.end(), [&](int a, int b) {
            return Lmin[a][k] < Lmin[b][k];
        });
        L.insert(L.begin(), 0);
        vector<int> L1max, R1min, L2min, R2max;
        L1max = R2max = vector<int>(n + 2, 0);
        R1min = L2min = vector<int>(n + 2, 1e6 + 5);
        for (int i = 1; i <= n; ++i) {
            L1max[i] = max(L1max[i - 1], Lmax[L[i]][k]);
            L2min[i] = min(L2min[i - 1], Rmin[L[i]][k + 1]);
        }
        for (int i = n; i >= 1; --i) {
            R1min[i] = min(R1min[i + 1], Lmin[L[i]][k]);
            R2max[i] = max(R2max[i + 1], Rmax[L[i]][k + 1]);
        }
        for (int i = 1; i < n; ++i) {
            if (L1max[i] < R1min[i + 1] && R2max[i + 1] < L2min[i]) {
                printf("YES\n");
                string s(n, 'R');
                for (int j = 1; j <= i; ++j) {
                    s[L[j] - 1] = 'B';
                }
                printf("%s %d\n", s.c_str(), k);
                return;
            }
        }
    }
    printf("NO\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}