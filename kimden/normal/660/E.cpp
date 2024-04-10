#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int mod = 1'000'000'007;

inline int add(int x, int y) { int z = x + y; if (z >= mod) z -= mod; return z; }
inline int sub(int x, int y) { int z = x + mod - y; if (z >= mod) z -= mod; return z; }
inline int mul(int x, int y) { return (x * (ll)y) % mod; }
inline int binpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p & 1)
            ans = mul(ans, x);
        x = mul(x, x);
        p >>= 1;
    }
    return ans;
}
inline int inv(int x) { return binpow(x, mod - 2); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    /*
     dp[n, i] = (m - 1) ^ (n - i) * C(n, i)
     sum_len ( m ^ len * prefsum[n, len - 1] )
     */
    int mm1 = m - 1;
    int invmm1 = inv(mm1);
    int c = 1;
    int p1 = binpow(mm1, n);
    int p2 = 1;
    int prefsum = binpow(m, n);
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = add(ans, mul(p2, prefsum));
        prefsum = sub(prefsum, mul(p1, c));
        p2 = mul(p2, m);
        p1 = mul(p1, invmm1);
        c = mul(c, n - i);
        c = mul(c, inv(i + 1));
    }
    cout << ans << "\n";
}