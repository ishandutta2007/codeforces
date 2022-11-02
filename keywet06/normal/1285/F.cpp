#include <bits/stdc++.h>

constexpr int N = 100005;

bool vis[N];

int n, tot;
int cnt[N], cnt2[N], pri[N], mu[N];

std::stack<int> stk;

void init(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) pri[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot && i * pri[j] <= n; ++j) {
            vis[i * pri[j]] = true;
            if (i % pri[j]) {
                mu[i * pri[j]] = -mu[i];
            } else {
                break;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    init(100000);
    std::cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        std::cin >> x;
        ++cnt[x];
    }
    long long ans = 0;
    for (int i = 1; i <= 100000; ++i) {
        for (int j = 100000 / i; j; --j) {
            if (!cnt[i * j]) continue;
            if (j == 1 && cnt[i] > 1)
                ans = std::max(ans, static_cast<long long>(i));
            int t = 0;
            for (int k = 1; k * k <= j; ++k) {
                if (j % k) continue;
                t += mu[k] * cnt2[k];
                if (k * k == j) break;
                t += mu[j / k] * cnt2[j / k];
            }
            int last = 0;
            while (t--) {
                do {
                    last = stk.top();
                    stk.pop();
                    for (int k = 1; k * k <= last; ++k) {
                        if (last % k) continue;
                        --cnt2[k];
                        if (k * k == last) break;
                        --cnt2[last / k];
                    }
                } while (std::gcd(last, j) > 1);
            }
            ans = std::max(ans, static_cast<long long>(i * j) * last);
            stk.push(j);
            for (int k = 1; k * k <= j; ++k) {
                if (j % k) continue;
                ++cnt2[k];
                if (k * k == j) break;
                ++cnt2[j / k];
            }
        }
        while (!stk.empty()) {
            int x = stk.top();
            stk.pop();
            for (int j = 1; j * j <= x; ++j) {
                if (x % j) continue;
                --cnt2[j];
                if (j * j == x) break;
                --cnt2[x / j];
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}