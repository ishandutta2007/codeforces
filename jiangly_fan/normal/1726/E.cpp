#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power (LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> f(n + 1), g(n + 1), ff(n + 1), h(n + 1);
        for (int i = 0; i <= n; i += 1) {
            g[i] = power(f[i] = i ? f[i - 1] * i % mod : 1, mod - 2);
            ff[i] = i >= 2 ? ff[i - 2] * i % mod : 1;
            h[i] = i >= 2 ? (h[i - 1] + (i - 1) * h[i - 2]) % mod : 1;
        }
        LL ans = 0;
        for (int i = 0; i * 2 <= n; i += 2) {
            int j = n - i * 2;
            LL pans = f[i + j] * g[i] % mod * g[j] % mod;
            if (i) pans = pans * ff[i - 1] % mod;
            pans = pans * power(2, i / 2) % mod;
            pans = pans * h[j] % mod;
            ans = (ans + pans) % mod;
        }
        cout << ans << "\n";
    }
}