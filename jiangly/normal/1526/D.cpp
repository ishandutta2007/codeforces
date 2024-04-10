#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.size();
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = std::string("ANOT").find(s[i]);
        }
        std::vector p{0, 1, 2, 3};
        std::vector sum(4, std::vector<int>(n + 1));
        for (int x = 0; x < 4; x++) {
            for (int i = n - 1; i >= 0; i--) {
                sum[x][i] = sum[x][i + 1] + (a[i] == x);
            }
        }
        i64 cur = -1;
        std::string ans;
        do {
            i64 cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; p[j] != a[i]; j++) {
                    cnt += sum[p[j]][i];
                }
            }
            if (cnt > cur) {
                cur = cnt;
                ans.clear();
                for (int i = 0; i < 4; i++) {
                    ans += std::string(sum[p[i]][0], "ANOT"[p[i]]);
                }
            }
        } while (std::next_permutation(p.begin(), p.end()));
        std::cout << ans << "\n";
    }
    return 0;
}