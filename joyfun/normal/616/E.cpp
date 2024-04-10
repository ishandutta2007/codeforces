#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007LL;

long long n, m;
long long r2;

long long pow_mod(long long x, long long k) {
    long long ans = 1;
    while (k) {
        if (k&1) ans = ans * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ans;
}

long long get(long long u, long long v) {
    u %= MOD;
    v %= MOD;
    long long len = ((v - u + 1) % MOD + MOD) % MOD;
    return (u + v) % MOD * len % MOD * r2 % MOD;
}

int main() {
    r2 = pow_mod(2LL, MOD - 2);
    scanf("%lld%lld", &n, &m);
    long long ans = m % MOD * (n % MOD) % MOD;
    long long u = 1;
    while (u <= m) {
        if (n / u == 0) break;
        long long v = min(m, n / (n / u));
        ans = (ans - get(u, v) * ((n / u) % MOD) % MOD + MOD) % MOD;
        u = v + 1;
    }
    printf("%lld\n", ans);
    return 0;
}