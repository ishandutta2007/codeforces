#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int binpow(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return binpow((x * x) % mod, n / 2);
    else return (binpow((x * x) % mod, n / 2) * x) % mod;
}

int solve(int n, int m, int l, int r) {
    if ((n * m) % 2 == 1) {
        return binpow((r - l + 1) % mod, n * m);
    }
    int x = 0;
    if ((r - l + 1) % 2 != 0) x = 1;
    return ((binpow(r - l + 1, n * m) + binpow(x, m * n)) * binpow(2, mod - 2)) % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    cout << solve(n, m, l, r);
}