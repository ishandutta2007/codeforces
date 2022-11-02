#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 105;

int n;
int a[N];

int64 dp[N][N], e[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= n; ++j) e[i][j] = -1e12;
        for (int j = i + 1; j <= n; ++j) {
            for (int l = 0; l <= n - i; ++l) {
                e[j][l] = -1e12;
                if (s[j - 1] == s[i]) e[j][l] = e[j - 1][l];
                for (int k = 1; k <= l && j - k; ++k)
                    e[j][l] = max(e[j][l], e[j - k][l - k] + dp[j - k][j]);
            }
            for (int l = 0; l <= j - i; ++l)
                dp[i][j] = max(e[j][l] + a[j - i - l], dp[i][j]);
        }
    }
    cout << dp[0][n];
}