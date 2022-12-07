#include <cstdio>

const int MOD = 1000000007;

const int N = 2000005;
int n;
int f[N];
int rf[N];

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = (long long)ans * x % MOD;
        x = (long long)x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (long long)f[i - 1] * i % MOD;
    rf[N - 1] = pow_mod(f[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) rf[i] = (long long)rf[i + 1] * (i + 1) % MOD;
    scanf("%d", &n);
    n++;
    printf("%d\n", ((long long)f[2 * n] * rf[n] % MOD * rf[n] % MOD - 1 + MOD) % MOD);
    return 0;
}