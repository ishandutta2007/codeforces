#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int mod = 998244353;

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = (llong)r * x % mod;
        x = (llong)x * x % mod;
        p >>= 1;
    }
    return r;
}

int n;
int fact[1000001];
int ifact[1000001];
int nCr(int n, int r) {
    if (n == r || r == 0) return 1;
    return (llong)fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = (llong)fact[i - 1] * i % mod;
    ifact[n] = pw(fact[n], mod - 2);
    for (int i = n; i--; ) ifact[i] = ifact[i + 1] * (i + 1ll) % mod;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        ans += (llong)nCr(n, i + 1) * i % mod * fact[n - i - 1] % mod * (n - i) % mod;
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}