#include <bits/stdc++.h>

using int64 = long long;

const int N = 55;

int n;
int Pro[N];

int64 Pow[N], Sco[N];
int64 dp[N][N];

std::vector<std::pair<int64, int64> > v;

bool works(int64 H) {
    v.clear();
    for (int i = 0; i < n; ++i) {
        Sco[i] = Pro[i] * H - Pow[i];
        v.push_back(std::make_pair(Pow[i], Sco[i]));
    }
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) dp[i][j] = -1e18;
    }
    dp[0][0] = 0;
    int Clock = 0;
    while (Clock < n) {
        int NClock = Clock;
        while (NClock < n && v[Clock].first == v[NClock].first) NClock++;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= i && j <= NClock - Clock; ++j) {
                int64 ctot = dp[Clock][i];
                for (int k = Clock; k < NClock - j; ++k) ctot += v[k].second;
                int Left = i - j + (NClock - Clock - j);
                dp[NClock][Left] = std::max(dp[NClock][Left], ctot);
            }
        }
        Clock = NClock;
    }
    for (int i = 0; i <= n; ++i) {
        if (dp[n][i] >= 0) return true;
    }
    return false;
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> Pow[i];
        Pow[i] *= 1000;
    }
    for (int i = 0; i < n; ++i) std::cin >> Pro[i];
    int64 lo = 0, hi = 1e12;
    while (lo < hi) {
        int64 mid = (lo + hi) / 2;
        if (works(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    std::cout << lo << "\n";
    return 0;
}