#include <iostream>
#include <vector>
#include <algorithm>
std::string s;
long long cnt[26], two[26][26];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> s;
    for (char c : s) {
        for (int i = 0; i < 26; ++i)
            two[i][c - 'a'] += cnt[i];
        ++cnt[c - 'a'];
    }
    long long ans = *std::max_element(cnt, cnt + 26);
    for (int i = 0; i < 26; ++i)
        ans = std::max(ans, *std::max_element(two[i], two[i] + 26));
    std::cout << ans << "\n";
    return 0;
}