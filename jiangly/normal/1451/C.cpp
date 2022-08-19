#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::string a, b;
        std::cin >> a >> b;
        int ca[26]{}, cb[26]{};
        for (auto c : a) ++ca[c - 'a'];
        for (auto c : b) ++cb[c - 'a'];
        bool ok = true;
        int sa = 0, sb = 0;
        for (int i = 0; i < 26; ++i) {
            sa += ca[i];
            sb += cb[i];
            if (ca[i] % k != cb[i] % k || sa < sb) ok = false;
        }
        if (ok) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    
    return 0;
}