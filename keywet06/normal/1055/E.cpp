#include <bits/stdc++.h>

const int N = 1600;

int n, s, m, k;
int a[N], go[N], ms[N];
int dp[N][N];

std::vector<int> vv;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> s >> m >> k;
    for (int i = 0; i < n; ++i) std::cin >> a[i], vv.push_back(a[i]);
    sort(vv.begin(), vv.end());
    vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
    for (int i = 0; i < n; ++i) go[i] = -1;
    for (int i = 0; i < s; ++i) {
        int l, r;
        std::cin >> l >> r, --l;
        for (int i = l; i < r; ++i) go[i] = std::max(go[i], r);
    }
    int l = -1;
    int r = vv.size();
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        memset(dp, 0, sizeof(dp));
        ms[0] = 0;
        for (int i = 0; i < n; ++i) ms[i + 1] = ms[i] + (a[i] <= vv[mid]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= s; ++j) {
                dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j]);
                if (j < s && go[i] > i) dp[go[i]][j + 1] = std::max(dp[go[i]][j + 1], dp[i][j] + ms[go[i]] - ms[i]);
            }
        }
        if (dp[n][m] >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == vv.size()) {
        std::cout << -1 << "\n";
    } else {
        std::cout << vv[r] << "\n";
    }
    return 0;
}