#include <bits/stdc++.h>

#define mkp std::make_pair
#define fi first
#define se second

using int64 = long long;

const int N = 205;

int n, k;
int next[N];

int64 S;
int64 x[N], y[N];

std::pair<int, int64> dp[N][N];

int check(int64 s) {
    S = s;
    int d = 0;
    for (int dis = 1; dis < n; ++dis) {
        for (int r = 0; r < n; ++r) {
            int l = (r + dis) % n;
            if (dis == 1 && (dp[l][r] = mkp(0, 0), 1)) continue;
            dp[l][r] = mkp(-1, -1);
            for (int k = next[r]; k != l; k = next[k]) {
                int64 s = (x[r] - x[l]) * (y[k] - y[l]) -
                          (x[k] - x[l]) * (y[r] - y[l]);
                auto s1 = dp[l][k], s2 = dp[k][r];
                int p1 = s1.fi + s2.fi;
                int64 p2 = s1.se + s2.se + s;
                if (p2 >= S) p2 = 0, ++p1;
                dp[l][r] = std::max(dp[l][r], mkp(p1, p2));
            }
        }
    }
    for (int i = 0; i < n; ++i) d = std::max(d, dp[i][next[i]].fi);
    return d;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i], next[i] = (i + 1) % n;
    int64 l = 0, r = (1ll << 60), mid;
    while (l + 1 < r) (check(l + r >> 1) >= k + 1 ? l : r) = l + r >> 1;
    std::cout << l << std::endl;
    return 0;
}