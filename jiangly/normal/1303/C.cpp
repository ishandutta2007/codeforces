#include <iostream>
#include <algorithm>
int t;
std::string s;
bool used[26];
void solve() {
    std::cin >> s;
    std::string ans(1, s[0]);
    std::fill(used, used + 26, false);
    used[s[0] - 'a'] = true;
    int pos = 0;
    for (int i = 1; i < int(s.length()); ++i) {
        if (!used[s[i] - 'a']) {
            if (pos == 0) {
                ans = s[i] + ans;
            } else if (pos == int(ans.length()) - 1) {
                ans += s[i];
                ++pos;
            } else {
                std::cout << "NO\n";
                return;
            }
            used[s[i] - 'a'] = true;
        } else if (pos > 0 && ans[pos - 1] == s[i]) {
            --pos;
        } else if (pos < int(ans.length()) - 1 && ans[pos + 1] == s[i]) {
            ++pos;
        } else {
            std::cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < 26; ++i)
        if (!used[i])
            ans += 'a' + i;
    std::cout << "YES\n";
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}