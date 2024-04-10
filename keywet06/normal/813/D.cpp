#include <bits/stdc++.h>

const int N = 5005;

short dp[N][N];

int a[N], nxt1[N], nxt2[N], nxt3[N];

std::vector<int> v[100005], V[10];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] % 7 == a[i] % 7) {
                nxt1[i] = j;
                break;
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] - a[i] == 1) {
                nxt2[i] = j;
                break;
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] - a[j] == 1) {
                nxt3[i] = j;
                break;
            }
        }
    }
    short mx = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = n; j > i; --j) v[a[j]].push_back(j), V[a[j] % 7].push_back(j);
        for (int j = i + 1; j <= n; ++j) {
            v[a[j]].pop_back();
            V[a[j] % 7].pop_back();
            dp[i][j] = std::max((int)dp[i][j], (!!i) + (!!j));
            dp[i][nxt1[j]] = std::max((int)dp[i][nxt1[j]], dp[i][j] + 1);
            dp[i][nxt2[j]] = std::max((int)dp[i][nxt2[j]], dp[i][j] + 1);
            dp[i][nxt3[j]] = std::max((int)dp[i][nxt3[j]], dp[i][j] + 1);
            if (i) {
                if (v[a[i] + 1].size()) {
                    dp[j][v[a[i] + 1].back()] = std::max((int)dp[j][v[a[i] + 1].back()], dp[i][j] + 1);
                }
                if (v[a[i] - 1].size()) {
                    dp[j][v[a[i] - 1].back()] = std::max((int)dp[j][v[a[i] - 1].back()], dp[i][j] + 1);
                }
                if (V[a[i] % 7].size()) {
                    dp[j][V[a[i] % 7].back()] = std::max((int)dp[j][V[a[i] % 7].back()], dp[i][j] + 1);
                }
            } else {
                for (int k = j + 1; k <= n; ++k) dp[j][k] = std::max((int)dp[j][k], dp[i][j] + 1);
            }
            mx = std::max(mx, dp[i][j]);
        }
    }
    std::cout << mx << std::endl;
    return 0;
}