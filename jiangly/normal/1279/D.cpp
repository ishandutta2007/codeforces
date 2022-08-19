#include <bits/stdc++.h>
using namespace std;
constexpr int P = 998'244'353, N = 1'000'000;
int fac[N + 1], inv[N + 1], p[N], cnt[N];
int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = 1LL * ans * a % P;
        a = 1LL * a * a % P;
        b >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= N; ++i)
        fac[i] = 1LL * fac[i - 1] * i % P;
    int invFac = power(fac[N], P - 2);
    for (int i = N; i >= 1; --i) {
        inv[i] = 1LL * invFac * fac[i - 1] % P;
        invFac = 1LL * invFac * i % P;
    }
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            --x;
            ++cnt[x];
            p[x] = (p[x] + inv[k]) % P;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans = (ans + 1LL * p[i] * cnt[i]) % P;
    ans = 1LL * ans * inv[n] % P * inv[n] % P;
    cout << ans << "\n";
    return 0;
}