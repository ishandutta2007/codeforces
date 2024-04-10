#include <bits/stdc++.h>

namespace oct {

void ios();

inline void ios() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}

}  // namespace oct

const int N = 5000 + 7;

int n, k, v, sum, now1, now2, a[N];
bool dp[N][N];
bool f[N][N];
std::vector<int> vc[2];

int main() {
    oct::ios();
    std::cin >> n >> k >> v;
    for (int i = 1; i <= n; i++) std::cin >> a[i], sum += a[i];
    if (sum < v) return std::cout << "NO\n", 0;
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (!dp[i][j]) continue;
            dp[i + 1][(j + a[i + 1]) % k] = true;
            f[i + 1][(j + a[i + 1]) % k] = true;
            dp[i + 1][j] = true, f[i + 1][j] = false;
        }
    }
    if (!dp[n][v % k]) return std::cout << "NO\n", 0;
    int tmp = v % k;
    for (int i = n; i >= 1; i--) {
        if (f[i][tmp]) {
            vc[0].push_back(i), tmp = ((tmp - a[i]) % k + k) % k;
        } else {
            vc[1].push_back(i);
        }
    }
    std::sort(vc[0].begin(), vc[0].end());
    std::sort(vc[1].begin(), vc[1].end());
    for (auto& t : vc[0]) now1 += a[t];
    now2 = sum - now1;
    std::cout << "YES\n";
    for (int i = 1; i < vc[0].size(); i++) {
        std::cout << "100000 " << vc[0][i] << ' ' << vc[0][0] << '\n';
    }
    for (int i = 1; i < vc[1].size(); i++) {
        std::cout << "100000 " << vc[1][i] << ' ' << vc[1][0] << '\n';
    }
    if (!vc[1].size()) vc[1].push_back(vc[0].back());
    if (!vc[0].size()) vc[0].push_back(vc[1].back());
    if (now1 < v) {
        std::cout << (v - now1) / k << ' ' << vc[1][0] << ' ' << vc[0][0]
                  << '\n';
    }
    if (now1 > v) {
        std::cout << (now1 - v) / k << ' ' << vc[0][0] << ' ' << vc[1][0]
                  << '\n';
    }
    return 0;
}