#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::vector<int> l;
        for (int i = 0, j; i < int(s.length()); i = j) {
            for (j = i; j < int(s.length()) && s[i] == s[j]; ++j)
                ;
            if (s[i] == '1')
                l.push_back(j - i);
        }
        std::sort(l.begin(), l.end(), std::greater<>());
        int ans = 0;
        for (int i = 0; i < int(l.size()); i += 2)
            ans += l[i];
        std::cout << ans << "\n";
    }
    return 0;
}