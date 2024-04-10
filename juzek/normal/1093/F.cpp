#include <cstdio>
#include <deque>

const int mod = 998244353;

int dp[100007][107];
int sum[100007];
int tab[1000007];

int main() {
    int N, K, len;
    scanf("%d%d%d", &N, &K, &len);
    std::deque<int> Q;
    sum[0] = 1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        if (!Q.empty() && Q.back() <= i - len)
            Q.pop_back();
        if (tab[i] != -1) {
            while (!Q.empty() && tab[Q.front()] == tab[i])
                Q.pop_front();
            Q.push_front(i);
        }
        long long tersum = 0;
        if (tab[i] == -1) {
            for (int w = 1; w <= K; w++) {
                long long ter = sum[i - 1];
                if (i >= len) {
                    if (Q.empty() || (Q.size() == 1 && tab[Q.back()] == w)) {
                        ter -= sum[i - len];
                        ter += dp[i - len][w];
                    }
                }
                dp[i][w] = int(ter % mod);
                tersum += dp[i][w];
            }
        } else {
            int w = tab[i];
            long long ter = sum[i - 1];
            if (i >= len) {
                if (Q.size() == 1 && tab[Q.back()] == w) {
                    ter -= sum[i - len];
                    ter += dp[i - len][w];
                }
            }
            dp[i][w] = int(ter % mod);
            tersum = dp[i][w];
        }
        sum[i] = int(tersum % mod);
    }
    printf("%d", (sum[N] + mod) % mod);
    return 0;
}