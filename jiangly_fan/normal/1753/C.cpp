#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        auto sa = a;
        ranges::sort(a);
        int c = 0;
        for (int i = 0; i < n; i += 1)
            c += a[i] != sa[i];
        vector<LL> inv(n + 1, 1);
        for (int i = 2; i <= n; i += 1)
            inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        LL ans = 0;
        for (int i = c / 2; i >= 1; i -= 1)
            ans = (ans + inv[i] * inv[i]) % mod;
        cout << (LL)n * (n - 1) / 2 % mod * ans % mod << "\n";
    }
}