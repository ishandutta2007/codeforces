#include <cstdio>

const int mod = 1000000007;

int tab[1000007];
int dp[1000007];
long long pot[1000007];

int main() {
    int N;
    scanf("%d", &N);
    int a;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        tab[a]++;
    }
    pot[0] = 1;
    for (int i = 1; i <= N; i++)
        pot[i] = (2 * pot[i - 1]) % mod;
    dp[1] = 1;
    long long wyn = 0;
    for (int i = 1; i <= 1000000; i++) {
        int suma = tab[i];
        for (int w = i + i; w <= 1000000; w += i) {
            suma += tab[w];
            dp[w] -= dp[i];
        }
        wyn += ((pot[suma] - 1) * dp[i]) % mod;
        wyn %= mod;
    }
    printf("%lld", (wyn + mod) % mod);
    return 0;
}