#include <bits/stdc++.h>
using namespace std;
constexpr int M = 50000 * 24;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    bitset<M + 1> dp[49][25];
    dp[0][0][0] = 1;
    for (int i = 0; i < 2 * n - 2; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j > 0)
                dp[i + 1][j] |= dp[i][j - 1] << a[i + 2];
        }
    }
    int total = accumulate(a.begin() + 2, a.end(), 0);
    int ans = 0;
    for (int i = 0; i <= M; ++i)
        if (dp[2 * n - 2][n - 1][i] == 1 && max(ans, total - ans) > max(i, total - i))
            ans = i;
    vector<int> f {a[0]}, s {a[1]};
    for (int i = 2 * n - 2, j = n - 1; i > 0; --i) {
        if (ans >= a[i + 1] && j > 0 && dp[i - 1][j - 1][ans - a[i + 1]] == 1) {
            --j;
            ans -= a[i + 1];
            f.push_back(a[i + 1]);
        } else {
            s.push_back(a[i + 1]);
        }
    }
    sort(f.begin(), f.end());
    sort(s.begin(), s.end(), greater<int>());
    for (int i = 0; i < n; ++i)
        cout << f[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i)
        cout << s[i] << " \n"[i == n - 1];
    return 0;
}