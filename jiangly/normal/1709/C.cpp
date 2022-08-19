#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int n = s.length() / 2;
    int open = n - std::count(s.begin(), s.end(), '(');
    int close = n - std::count(s.begin(), s.end(), ')');
    if (open == 0 || close == 0) {
        std::cout << "YES\n";
        return;
    }
    int cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '?') {
            if (cur < open - 1 || cur == open) {
                s[i] = '(';
            } else {
                s[i] = ')';
            }
            cur++;
        }
    }
    int sum = 0;
    for (auto c : s) {
        sum += c == '(' ? 1 : -1;
        if (sum < 0) {
            std::cout << "YES\n";
            return;
        }
    }
    assert(sum == 0);
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}