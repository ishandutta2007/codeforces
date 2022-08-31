#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
constexpr int P = 1'000'000'007;
int n;
std::vector<int> a, b, mask, cnt;
std::vector<std::vector<int>> binom, dp;
std::vector<bool> vis;
std::pair<int, int> solve() {
    if (int(b.size()) == 1)
        return {0, 1};
    std::sort(b.begin(), b.end());
    int cntS = 0;
    for (int i = 0; i < int(b.size()); ++i) {
        bool ok = true;
        for (int j = 0; j < i; ++j)
            if (b[i] % b[j] == 0)
                ok = false;
        if (ok) {
            std::swap(b[i], b[cntS]);
            ++cntS;
        }
    }
    int cntT = b.size() - cntS;
    mask.assign(cntT, 0);
    for (int i = 0; i < cntT; ++i)
        for (int j = 0; j < cntS; ++j)
            if (b[i + cntS] % b[j] == 0)
                mask[i] |= 1 << j;
    dp.assign(1 << cntS, std::vector<int>(cntT));
    cnt.assign(1 << cntS, 0);
    for (int i = 0; i < cntT; ++i)
        ++cnt[mask[i]];
    for (int i = 0; i < cntS; ++i)
        for (int j = 0; j < (1 << cntS); ++j)
            if (j >> i & 1)
                cnt[j] += cnt[j ^ (1 << i)];
    for (int i = 0; i < cntT; ++i)
        ++dp[mask[i]][0];
    for (int s = 0; s < (1 << cntS); ++s) {
        for (int i = 0; i < cntT; ++i) {
            for (int j = 0; j < cntT; ++j)
                if ((s | mask[j]) != s && (mask[j] & s))
                    dp[s | mask[j]][i + 1] = (dp[s | mask[j]][i + 1] + dp[s][i]) % P;
            if (i + 1 < cntT)
                dp[s][i + 1] = (dp[s][i + 1] + 1LL * dp[s][i] * (cnt[s] - i - 1)) % P;
        }
    }
    return {cntT - 1, dp.back().back()};
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    vis.resize(n);
    binom.assign(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % P;
    }
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int tot = 0, ans = 1;
    for (int i = 0; i < n; ++i) {
        if (vis[i])
            continue;
        b = {i};
        vis[i] = true;
        for (int j = 0; j < int(b.size()); ++j) {
            int u = b[j];
            for (int k = 0; k < u; ++k) {
                if (!vis[k] && a[u] % a[k] == 0) {
                    vis[k] = true;
                    b.push_back(k);
                }
            }
            for (int k = u + 1; k < n; ++k) {
                if (!vis[k] && a[k] % a[u] == 0) {
                    vis[k] = true;
                    b.push_back(k);
                }
            }
        }
        for (int &j : b)
            j = a[j];
        auto [cnt, res] = solve();
        tot += cnt;
        ans = 1LL * ans * binom[tot][cnt] % P * res % P;
    }
    std::cout << ans << "\n";
    return 0;
}