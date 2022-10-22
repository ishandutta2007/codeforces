#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int qpow(int x, int n) {
    int ans = 1;
    for (; n; n >>= 1, x = 1LL * x * x % mod)
        if (n & 1) ans = 1LL * ans * x % mod;
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%lld\n", 1LL * qpow(2, m) * qpow(n + 1, m - 1) % mod * (n + 1 - m) % mod);
    return 0;
}