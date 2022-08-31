#include <iostream>
#include <vector>
#include <string>
#include <set>
int n ,k;
std::vector<std::string> s;
std::set<std::string> a;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    s.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::string need;
            for (int l = 0; l < k; ++l) {
                if (s[i][l] == s[j][l]) {
                    need += s[i][l];
                } else {
                    need += 'S' ^ 'E' ^ 'T' ^ s[i][l] ^ s[j][l];
                }
            }
            if (a.find(need) != a.end())
                ++ans;
        }
        a.insert(s[i]);
    }
    std::cout << ans << "\n";
    return 0;
}