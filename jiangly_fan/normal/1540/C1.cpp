#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 100 + 1;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int c[maxn], b[maxn], sb[maxn], ssb[maxn];
LL dp[maxn * maxn];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 1) cin >> c[i];
    for (int i = 1; i < n; i += 1) cin >> b[i];
    for (int i = 1; i < n; i += 1) sb[i + 1] = sb[i] + b[i];
    for (int i = 1; i < n; i += 1) ssb[i + 1] = ssb[i] + sb[i + 1];
    int q;
    for (cin >> q; q; q -= 1) {
        int x;
        cin >> x;
        int sc = 0;
        for (int i = 1; i <= n; i += 1) sc += c[i];
        for (int i = 0; i <= sc; i += 1) dp[i] = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; i += 1)
            for (int j = sc; j >= 0; j -= 1) {
                LL cur = 0;
                if (j - ssb[i] >= i * x)
                    for (int k = 0; k <= c[i] and k <= j; k += 1)
                        cur += dp[j - k];
                dp[j] = cur % mod;
            }
        LL ans = 0;
        for (int i = 0; i <= sc; i += 1) ans += dp[i];
        cout << ans % mod << "\n";
    }
    return 0;
}