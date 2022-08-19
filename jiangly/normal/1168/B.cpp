#include <bits/stdc++.h>

constexpr int N = 3e5;

int n;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> s;
    n = s.length();
    
    int64_t ans = 0;
    
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n) {
            bool ok = false;
            for (int k = 1; 2 * k <= j - i; ++k)
                if (s[j] == s[j - k] && s[j] == s[j - k - k])
                    ok = true;
            if (ok)
                break;
            ++j;
        }
        ans += n - j;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}