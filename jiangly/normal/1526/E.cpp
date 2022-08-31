#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 998244353;
int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P)
        if (b & 1)
            res = 1ll * res * a % P;
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> s(n + 1);
    s[0] = n;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
    }
    std::vector<int> rk(n + 1);
    for (int i = 0; i <= n; i++) {
        rk[s[i]] = i;
    }
    int equal = n - 1;
    for (int i = 1; i < n; i++) {
        if (rk[s[i] + 1] > rk[s[i + 1] + 1]) {
            equal--;
        }
    }
    int num = 1, den = 1;
    for (int i = 0; i < n; i++) {
        num = i64(num) * (k + equal - i) % P;
        den = i64(den) * (i + 1) % P;
    }
    int ans = i64(num) * power(den, P - 2) % P;
    std::cout << ans << "\n";
    return 0;
}