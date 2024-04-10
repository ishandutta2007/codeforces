#include <bits/stdc++.h>

using int64 = long long;

const int64 INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int64> l(n);
    for (int i = 0; i < n; ++i) std::cin >> l[i];
    std::string s;
    std::cin >> s;
    int64 cnt[6] = {};
    cnt[5] = INF;
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            cnt[3] = std::max(cnt[3], INF);
            cnt[1] += 2 * l[i];
        } else if (s[i] == 'G') {
            cnt[2] += 2 * l[i];
        }
        ans += l[i];
        int64 t = l[i];
        for (int j = 1; t > 0; ++j) {
            int64 v = std::min(cnt[j], t);
            cnt[j] -= v;
            t -= v;
            ans += v * j;
        }
    }
    std::cout << ans << "\n";
    return 0;
}