#include <bits/stdc++.h>

const int INF = 1e9 + 1;
const int MAXA = 1e7;
std::vector<int> primes;
int mind[MAXA + 1];

int main() {
    for (int i = 2; i <= MAXA; ++i) {
        if (mind[i] == 0) {
            primes.emplace_back(i);
            mind[i] = i;
        }
        for (auto &x : primes) {
            if (x > mind[i] || x * i > MAXA) break;
            mind[x * i] = x;
        }
    }
    std::vector<int> cnt(MAXA + 1);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n, 1);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            int cnt = 0, last = 0;
            while (x > 1) {
                int p = mind[x];
                if (last == p) {
                    ++cnt;
                } else {
                    if (cnt % 2 == 1) a[i] *= last;
                    last = p;
                    cnt = 1;
                }
                x /= p;
            }
            if (cnt % 2 == 1) a[i] *= last;
        }
        std::vector<std::vector<int>> mnleft(n, std::vector<int>(k + 1));
        for (int j = 0; j <= k; j++) {
            int l = n, now = 0;
            for (int i = n - 1; i >= 0; i--) {
                while (l - 1 >= 0 && now + (cnt[a[l - 1]] > 0) <= j) {
                    l--;
                    now += (cnt[a[l]] > 0);
                    cnt[a[l]]++;
                }
                mnleft[i][j] = l;
                if (cnt[a[i]] > 1) now--;
                cnt[a[i]]--;
            }
        }
        std::vector<std::vector<int> > dp(n + 1, std::vector<int>(k + 1, INF));
        for (auto &c : dp[0]) c = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0) dp[i][j] = dp[i][j - 1];
                for (int lst = 0; lst <= j; lst++) {
                    dp[i][j] =
                        std::min(dp[i][j], dp[mnleft[i - 1][lst]][j - lst] + 1);
                }
            }
        }
        int ans = INF;
        for (auto &c : dp.back()) ans = std::min(ans, c);
        std::cout << ans << "\n";
    }
    return 0;
}