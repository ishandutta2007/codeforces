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
        int n, k;
        std::string s;
        std::cin >> n >> k >> s;
        int lg = std::__lg(n) + 1;
        std::string t(std::max(0, k - lg), '0');
        int l = k - t.length();
        int mask = 0, cnt = 0;
        for (int i = 0; i < k - l; ++i) {
            cnt += s[i] - '0';
        }
        for (int i = k - l; i < k - 1; ++i) {
            mask = (mask << 1) | (s[i] - '0');
        }
        std::vector<bool> bad(1 << l);
        for (int i = k - 1; i < n; ++i) {
            mask = ((mask << 1) | (s[i] - '0')) & ((1 << l) - 1);
            if (cnt == k - l) {
                bad[((1 << l) - 1) ^ mask] = true;
            }
            cnt = cnt - (s[i - k + 1] - '0') + (s[i - l + 1] - '0');
        }
        int ans = 0;
        while (ans < (1 << l) && bad[ans]) {
            ++ans;
        }
        if (ans == (1 << l)) {
            std::cout << "NO\n";
            continue;
        }
        for (int i = l - 1; i >= 0; --i) {
            t += '0' + (ans >> i & 1);
        }
        std::cout << "YES\n";
        std::cout << t << "\n";
    }
    return 0;
}