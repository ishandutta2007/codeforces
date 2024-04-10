#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 5e3 + 100;
int f[MAXN], invf[MAXN];

int binpow(int x, int n, int p) {
    int res = 1;
    while (n) {
        if (n % 2 == 0) {
            x = (x * x) % p;
            n /= 2;
        } else {
            res = (res * x) % p;
            n--;
        }
    }
    return res;
}

main() {
    int n, p;
    cin >> n >> p;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = (f[i - 1] * i) % p;
    }
    invf[n] = binpow(f[n], p - 2, p);
    for (int i = n; i > 0; --i) {
        invf[i - 1] = (invf[i] * i) % p;
    }
    int ans = 0;
    if (n % 2 == 0) {
        ans += n * f[n - 2];
        ans %= p;
    }
    for (int len = 2; (len - 1) * 2 < n; ++len) {
        for (int c = 2; c <= len; ++c) {
            int cur = (n * (len - n % 2)) % p;
            cur = (cur * f[n - c - 1]) % p;
            cur = (cur * f[len - 2]) % p;
            cur = (cur * invf[c - 2]) % p;
            cur = (cur * invf[len - c]) % p;
            ans = (ans + cur) % p;
        }
    }
    cout << ans;
    return 0;
}