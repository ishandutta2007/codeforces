#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int& ai : a) cin >> ai;
    if (a[0] == 0) {
        cout << 0;
        return 0;
    }
    a.push_back(0);
    int m = 500000;
    vector<LL> f(m + 1), g(m + 1);
    for (int i = 0; i <= m; i += 1)
        f[i] = i ? f[i - 1] * i % mod : 1;
    g[m] = power(f[m], mod - 2);
    for (int i = m; i; i -= 1)
        g[i - 1] = g[i] * i % mod;
    auto D = [&](int n, int m) -> LL {
        return f[n + m] * g[n] % mod * g[m] % mod;
    };
    LL ans = 0;
    for (int i = 0; i <= n; i += 1) if (a[i]) {
        ans = (ans + D(i, a[i] - 1)) % mod;
        for (int j = a[i + 1]; j < a[i]; j += 1)
            ans = (ans + D(i, j)) % mod;
    }
    cout << (ans + mod - 1) % mod;
    return 0;
}