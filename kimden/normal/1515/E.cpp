#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

inline int add(int x, int y, int mod) {
    int z = x + y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}
inline int sub(int x, int y, int mod) {
    int z = x + mod - y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}
inline int mul(int x, int y, int mod) {
    return (x * (ll)y) % mod;
}
inline int binpow(int x, int p, int mod) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = mul(ans, x, mod);
        }
        x = mul(x, x, mod);
        p >>= 1;
    }
    return ans;
}
inline int inv(int x, int mod) {
    return binpow(x, mod - 2, mod);
}
int p2[1000];
int f[1000];
int invf[1000];

int dp[1020][1020];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, mod;
    cin >> n >> mod;
    p2[0] = 1;
    f[0] = 1;
    invf[0] = 1;
    for (int i = 1; i < 1000; ++i) {
        p2[i] = mul(p2[i - 1], 2, mod);
        f[i] = mul(f[i - 1], i, mod);
        invf[i] = inv(f[i], mod);
    }
    dp[0][0] = 1;
    for (int i = 0; i <= 420; ++i) {
        for (int j = 0; j <= 420; ++j) {
            for (int k = 1; k <= 420; ++k) {
                int coeff = mul(p2[k - 1], invf[k], mod);
                dp[i + k + 1][j + k] = add(dp[i + k + 1][j + k], mul(dp[i][j], coeff, mod), mod);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 420; ++i) {
        ans = add(ans, mul(f[i], dp[n + 1][i], mod), mod);
    }
    cout << ans << "\n";



}