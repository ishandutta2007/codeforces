#include <bits/stdc++.h>
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    int n = s.length();
    int ans = 0, res = 0, sum = 0, pw = 1;
    for (int i = n - 1; i >= 0; --i) {
        res = (10ll * res + sum) % P;
        ans = (ans + (1ll * i * (i + 1) / 2 % P * pw + res) % P * (s[i] - '0')) % P;
        sum = (sum + pw) % P;
        pw = 10ll * pw % P;
    }
    std::cout << ans << "\n";
    
    return 0;
}