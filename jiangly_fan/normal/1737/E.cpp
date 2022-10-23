#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        vector<LL> pw(n + 1, 1), f(n + 1), g(n + 2);
        for (int i = 1; i <= n; i += 1)
            pw[i] = pw[i - 1] * (mod + 1) / 2 % mod;
        LL sum = 0;
        for (int i = n; i >= 2; i -= 1) {
            f[i] = i == n ? 1 : pw[1];
            f[i] = f[i] * pw[(i + 1) / 2 - 1] % mod;
            if (2 * i <= n) f[i] = f[i] * (1 + g[2 * i]) % mod;
            g[i] = (g[i + 1] + mod - f[i]) % mod;
        }
        for (int i = 1; i <= n; i += 1) {
            cout << f[i] << "\n";
            sum = (sum + f[i]) % mod;
        }
        assert(sum == 1);
    }
}