#include <cstdio>
#include <iostream>

const int mod = 1000000007;
long long silnia[100007];

long long binpow(long long a, int b) {
    long long ret = 1;
    while (b != 0) {
        if (b % 2 == 1) {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return ret;
}

long long sym(int n, int k) {
    if (k > n || n < 0 || k < 0)
        return 0LL;
    return (silnia[n] * binpow((silnia[k] * silnia[n - k]) % mod, mod - 2)) % mod;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    std::string s;
    std::cin >> s;
    silnia[0] = 1LL;
    for (int i = 1; i <= N; i++) {
        silnia[i] = (i * silnia[i - 1]) % mod;
    }
    long long wsp = 0;
    long long ans = 0;
    long long q = 1;
    for (auto i = (int) s.length() - 1; i >= 0; i--) {
        ans += (wsp * (s[i] - '0')) % mod;
        ans += (sym(i, K) * (s[i] - '0') * q) % mod;
        ans %= mod;
        wsp += q * sym(i - 1, K - 1);
        q = (q * 10) % mod;
        wsp %= mod;
    }
    printf("%I64d\n", ans);
    return 0;
}