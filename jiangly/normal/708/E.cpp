#include <bits/stdc++.h>
using namespace std;
constexpr int P = 1000000007;
int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = 1LL * result * base % P;
        base = 1LL * base * base % P;
        exp >>= 1;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b, k;
    cin >> n >> m >> a >> b >> k;
    int pr = 1LL * a * power(b, P - 2) % P;
    vector<int> factorial(k + 1), inv_factorial(k + 1);
    factorial[0] = 1;
    for (int i = 1; i <= k; ++i)
        factorial[i] = 1LL * factorial[i - 1] * i % P;
    inv_factorial[k] = power(factorial[k], P - 2);
    for (int i = k; i >= 1; --i)
        inv_factorial[i - 1] = 1LL * inv_factorial[i] * i % P;
    auto binom = [&](int n, int m) {return 1LL * factorial[n] * inv_factorial[m] % P * inv_factorial[n - m] % P;};
    vector<int> p(m + 1);
    for (int i = 0; i <= min(m, k); ++i)
        p[i] = 1LL * binom(k, i) * power(pr, i) % P * power((1 - pr + P) % P, k - i) % P;
    vector<vector<int>> dp(2, vector<int>(m + 1));
    int cur = 0;
    dp[cur][m] = 1;
    for (int i = 1; i <= n; ++i) {
        cur ^= 1;
        int sp = 0, ss = 0;
        for (int j = 0; j <= m; ++j) {
            dp[cur][j] = (1LL * sp * (dp[cur ^ 1][m] - dp[cur ^ 1][m - j] + P) % P - ss + P) * p[m - j] % P;
            sp = (sp + p[j]) % P;
            ss = (ss + 1LL * p[j] * dp[cur ^ 1][j]) % P;
        }
        for (int j = 1; j <= m; ++j)
            dp[cur][j] = (dp[cur][j] + dp[cur][j - 1]) % P;
    }
    cout << dp[cur][m] << endl;
    return 0;
}