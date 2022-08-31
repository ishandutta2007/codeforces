// lg
#include <iostream>
#include <vector>
int t, n, m;
std::string s;
std::vector<int> sum;
int cnt[26];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m >> s;
        sum.assign(n, 0);
        for (int i = 0; i < m; ++i) {
            int p;
            std::cin >> p;
            ++sum[p - 1];
        }
        ++sum[n - 1];
        for (int i = n - 2; i >= 0; --i)
            sum[i] += sum[i + 1];
        std::fill(cnt, cnt + 26, 0);
        for (int i = 0; i < n; ++i)
            cnt[s[i] - 'a'] += sum[i];
        for (int i = 0; i < 26; ++i)
            std::cout << cnt[i] << " \n"[i == 25];
    }
    return 0;
}