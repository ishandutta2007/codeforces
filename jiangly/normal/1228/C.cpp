#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
constexpr int MOD = 1e9 + 7;
int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = 1ll * ans * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
void solve(int case_id) {
    int x;
    LL n;
    cin >> x >> n;
    vector<int> primes;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            primes.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        primes.push_back(x);
    int ans = 1;
    for (int p : primes) {
        LL tot = 0;
        for (LL y = n; y /= p;)
            tot += y;
        ans = 1ll * ans * power(p, tot % (MOD - 1)) % MOD;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}