#include <cstdio>
#include <algorithm>


const int mod = 998244353;
int tab[1007];
int dp[1007][1007];
int N, K;

int wypelnijDp(int x) {
    for (int i = 1; i <= N; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= K; i++) {
        int sum = 0;
        int las = 0;
        for (int w = 1; w <= N; w++) {
            for (int z = las + 1; z < w; z++) {
                if (tab[w] - tab[z] < x)
                    break;
                las = z;
                sum += dp[i - 1][z];
                sum %= mod;
            }
            dp[i][w] = sum;
        }
    }
    int ret = 0;
    for (int w = 1; w <= N; w++) {
        ret += dp[K][w];
        ret %= mod;
    }
    return ret;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", &tab[i]);
    std::sort(tab + 1, tab + N + 1);
    int odp = 0;
    for (int i = 1;; i++) {
        int hm = wypelnijDp(i);
        if (hm == 0)
            break;
        odp += hm;
        odp %= mod;
    }
    printf("%d", odp);
    return 0;
}