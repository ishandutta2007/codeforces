#include <cstdio>
#include <algorithm>

const int mod = 1000000007;

long long binpow(long long p, int n) {
    long long ret = 1;
    while (n != 0) {
        if (n % 2 == 1) {
            ret *= p;
            ret %= mod;
        }
        p *= p;
        p %= mod;
        n /= 2;
    }
    return ret;
}

long long silnia[2000007], odw[2000007];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    silnia[0] = 1;
    odw[0] = 1;
    for (int i = 1; i <= 2000000; i++) {
        silnia[i] = silnia[i - 1] * i;
        silnia[i] %= mod;
        odw[i] = binpow(silnia[i], mod - 2);
    }
    long long wyn = 0;
    if (N - 1 <= M) {
        wyn = ((silnia[M - 1] * odw[N - 2]) % mod * odw[M - 1 - (N - 2)]) % mod;
        wyn *= silnia[N - 2];
        wyn %= mod;
    }
    for (int x = 2; x < N; x++) {
        if (x - 1 > M)
            break;
        long long ter = x;
        ter *= binpow(N, N - x - 1);
        ter %= mod;
        ter *= ((silnia[M - 1] * odw[x - 2]) % mod * odw[M - 1 - (x - 2)]) % mod;
        ter %= mod;
        ter *= binpow(M, N - x);
        ter %= mod;
        ter *= (silnia[N - 2] * odw[N -x]) % mod;
        ter %= mod;
        wyn += ter;
    }
    wyn %= mod;
    printf("%lld\n", wyn);
    return 0;
}