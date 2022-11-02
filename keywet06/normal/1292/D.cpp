#include <bits/stdc++.h>

const int N = 5000;
const int M = N + 1;
const int R = 669;
const long long INF = 1000000000000000000;

int cnt, n;
int val[M], id[M], lcp[M], len[R + 1][M], vpre[M];
int sum[M][R];

long long dp[R + 1][M];
long long pre[M][R];

void sieve() {
    for (int i = 2; i <= N; ++i) {
        int x = i;
        std::copy(sum[i - 1], sum[i - 1] + cnt, sum[i]);
        for (int j = 2; j < i; ++j) {
            while (x % j == 0) {
                x /= j;
                ++sum[i][id[j]];
            }
        }
        if (x == i) {
            id[i] = cnt++;
            ++sum[i][id[i]];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve();
    for (int i = 0; i <= N; ++i) std::reverse(sum[i], sum[i] + R);
    for (int i = 2; i <= N; ++i) {
        while (lcp[i] < cnt && sum[i - 1][lcp[i]] == sum[i][lcp[i]]) ++lcp[i];
    }
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x == 0) x = 1;
        ++val[x];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < R; ++j) {
            pre[i][j] = pre[i - 1][j] + 1LL * val[i] * sum[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) vpre[i] = vpre[i - 1] + val[i];
    for (int l = 0; l <= R; ++l) {
        len[l][N] = 1;
        for (int i = N - 1; i >= 1; --i) {
            if (lcp[i + 1] >= l) {
                len[l][i] = len[l][i + 1] + 1;
            } else {
                len[l][i] = 1;
            }
        }
    }
    dp[0][1] = 0;
    long long ans = INF, cost = 0;
    for (int i = 0; i < R; ++i) cost += pre[N][i];
    for (int i = 0; i <= R; ++i) {
        std::fill(dp[i + 1], dp[i + 1] + M, INF);
        for (int j = 1; j <= N; ++j) {
            if (dp[i][j] == INF) continue;
            ans = std::min(ans, dp[i][j] + cost);
            if (i == R) continue;
            for (int k = j; k < j + len[i][j]; k += len[i + 1][k]) {
                dp[i + 1][k] =
                    std::min(dp[i + 1][k],
                             dp[i][j] + 2 * pre[j - 1][i] - pre[k - 1][i] +
                                 pre[N][i] - pre[k + len[i + 1][k] - 1][i] +
                                 1LL * sum[k][i] *
                                     (vpre[k - 1] + vpre[N] -
                                      2 * vpre[j + len[i][j] - 1] +
                                      vpre[k + len[i + 1][k] - 1]));
            }
        }
        if (i == R) break;
        cost -= pre[N][i];
    }
    std::cout << ans << "\n";
    return 0;
}