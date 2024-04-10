#include <iostream>
#include <vector>
int t;
std::string a, b;
std::vector<std::vector<int>> next;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b;
        next.assign(a.length() + 1, std::vector<int>(26, -1));
        for (int i = a.length() - 1; i >= 0; --i) {
            next[i] = next[i + 1];
            next[i][a[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < int(b.length()); ) {
            int j = i, pos = 0;
            while (j < int(b.length()) && next[pos][b[j] - 'a'] != -1) {
                pos = next[pos][b[j] - 'a'] + 1;
                ++j;
            }
            if (i == j) {
                ans = -1;
                break;
            }
            ++ans;
            i = j;
        }
        std::cout << ans << "\n";
    }
    return 0;
}