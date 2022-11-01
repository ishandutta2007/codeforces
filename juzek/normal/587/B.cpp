#include <cstdio>
#include <algorithm>

int tab[1000007], norm[1000007], dr[1000007];
long long dp[1000007];

const int mod = 1000000007;

int main() {
    int N, K;
    long long L;
    scanf("%d%lld%d", &N, &L, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        norm[i] = tab[i];
    }
    std::sort(tab + 1, tab + N + 1);
    int reszta = int(L % N);
    for (int i = 1; i <= reszta; i++)
        dr[i] = norm[i];
    std::sort(dr + 1, dr + reszta + 1);
    long long sum = 1;
    long long wyn = 0;
    long long pelne = L / N;
    K = (int) std::min((long long) K, (L + N - 1) / N);
    for (int w = 1; w <= K; w++) {
        int teri = 1;
        for (int i = 1; i <= N; i++) {
            if (tab[i] != tab[i - 1])
                sum += dp[i];
            sum %= mod;
            if (tab[i] == dr[teri]) {
                wyn += sum;
                wyn %= mod;
                teri++;
            }
            dp[i] = sum;
            wyn += sum * ((pelne - w + 1) % mod) % mod;
            wyn %= mod;
        }
        long long ter = 0;
        for (int i = 1; i <= N; i++) {
            ter += dp[i];
            if (tab[i] != tab[i + 1]) {
                for (int k = i; tab[k] == tab[i]; k--)
                    dp[k] = ter;
                ter = 0;
            }
        }
        sum = 0;
    }
    printf("%lld", wyn);
    return 0;
}