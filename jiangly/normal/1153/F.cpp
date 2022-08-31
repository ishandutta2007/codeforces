#include <bits/stdc++.h>
using namespace std;
constexpr int P = 998244353;
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
    int n, k, l;
    cin >> n >> k >> l;
    vector<vector<int>> f(n + 1);
    for (int i = 0; i <= n; ++i)
        f[i].resize(n + 1);
    for (int y = 0; y <= n; ++y)
        f[0][y] = 1;
    for (int x = 1; x <= n; ++x)
        for (int y = x; y <= n; ++y)
            f[x][y] = (f[x][y - 1] + 1LL * f[x - 1][y] * (y - x + 1)) % P;
    vector<int> factorial(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i)
        factorial[i] = 1LL * factorial[i - 1] * i % P;
    int ans = 0;
    for (int i = 1; i < 2 * n; ++i) {
        for (int j = k + ((i - k) & 1); j <= min(i, 2 * n - i); j += 2) {
            int x = (i - j) / 2, y = (i + j) / 2;
            ans = (ans + 1LL * f[x][y] * f[n - y][n - x] % P * factorial[abs(x - y)]) % P;
        }
    }
    ans = 1LL * ans * l % P * power(1LL * f[n][n] * (2 * n + 1) % P, P - 2) % P;
    cout << ans << endl;
    return 0;
}