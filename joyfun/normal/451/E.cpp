#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;
const int N = 25;
long long n, s, f[N];

long long pow(long long x, long long k) {
    long long ans = 1;
    while (k) {
    if (k&1) ans = ans * x % MOD;
    x = x * x % MOD;
    k >>= 1;
    }
    return ans;
}

long long C(long long n, long long m) {
    if (m > n) return 0;
    m = min(m, n - m);
    long long zi = 1, mu = 1;
    for (long long i = 0; i < m; i++) {
    zi = zi * (n - i) % MOD;
    mu = mu * (i + 1) % MOD;
    }
    return zi * pow(mu, MOD - 2) % MOD;
}

long long Lucas(long long n, long long m, long long p) {
    if (m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p, p) % p;
}

int bitcount(long long x) {
    return x == 0 ? 0 : bitcount(x / 2) + (x&1);
}

int main() {
    scanf("%lld%lld", &n, &s);
    for (int i = 0; i < n; i++)
    scanf("%lld", &f[i]);
    long long maxs = (1<<n);
    long long ans = 0;
    for (int i = 0; i < maxs; i++) {
    long long sum = s;
    for (int j = 0; j < n; j++) {
        if (i&(1<<j)) {
        sum -= (f[j] + 1);
        }
        if (sum < 0) break;
    }
    if (sum < 0) continue;
    int tmp = bitcount(i);
    if (tmp&1) ans -= Lucas(sum + n - 1, n - 1, MOD);
    else ans += Lucas(sum + n - 1, n - 1, MOD);
    }
    ans = (ans % MOD + MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}