#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
constexpr int MAX_N = 1000, MOD = 1e9 + 7;
int n, m;
int a[MAX_N][MAX_N];
void solve(int case_id) {
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j)
            a[i][j] = 1;
        if (x != m)
            a[i][x] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            if (a[j][i] == 0) {
                cout << "0\n";
                return;
            }
            a[j][i] = 1;
        }
        if (x != n) {
            if (a[x][i] == 1) {
                cout << "0\n";
                return;
            }
            a[x][i] = 0;
        }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == -1)
                ans = 2 * ans % MOD;
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}