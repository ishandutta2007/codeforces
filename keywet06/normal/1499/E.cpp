#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353;
const int B = 2;
const int N = 1005;

int n, m;
int c1[N], c2[N];

int64 ans;
int64 dp[N][N][B];

std::string s1, s2;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> s1 >> s2, n = s1.length(), m = s2.length();
    c1[0] = c2[0] = 1;
    for (int i = 1; i < n; ++i) c1[i] = s1[i] != s1[i - 1] ? c1[i - 1] + 1 : 1;
    for (int i = 1; i < m; ++i) c2[i] = s2[i] != s2[i - 1] ? c2[i - 1] + 1 : 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s1[i] != s2[j]) dp[i][j][0] = c2[j], dp[i][j][1] = c1[i];
            if (i) {
                if (s1[i] != s1[i - 1]) dp[i][j][0] += dp[i - 1][j][0];
                if (s1[i] != s2[j]) dp[i][j][0] += dp[i - 1][j][1];
            }
            if (j) {
                if (s2[j] != s1[i]) dp[i][j][1] += dp[i][j - 1][0];
                if (s2[j] != s2[j - 1]) dp[i][j][1] += dp[i][j - 1][1];
            }
            ans += dp[i][j][0] %= P, ans += dp[i][j][1] %= P;
        }
    }
    ans %= P;
    std::cout << ans << std::endl;
    return 0;
}