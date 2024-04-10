#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    int n = s.length();
    
    std::vector<int> fail(n + 10 + 1);
    fail[0] = -1;
    std::vector<std::array<int, 26>> f(n + 10 + 1);
    f[0][s[0] - 'a'] = 1;
    fail[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (j == s[i] - 'a') {
                f[i][j] = i + 1;
                fail[i + 1] = f[fail[i]][j];
            } else {
                f[i][j] = f[fail[i]][j];
            }
        }
    }
    
    int q;
    std::cin >> q;
    
    while (q--) {
        std::string t;
        std::cin >> t;
        
        int m = t.length();
        for (int i = n; i < n + m; i++) {
            for (int j = 0; j < 26; j++) {
                if (j == t[i - n] - 'a') {
                    f[i][j] = i + 1;
                    fail[i + 1] = f[fail[i]][j];
                } else {
                    f[i][j] = f[fail[i]][j];
                }
            }
            std::cout << fail[i + 1] << " \n"[i == n + m - 1];
        }
    }
    
    return 0;
}