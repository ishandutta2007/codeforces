#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::string s;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> s;
    if (2 * std::count(s.begin(), s.end(), '(') != n) {
        std::cout << -1 << "\n";
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ) {
        int j = i, balance = 0;
        bool good = true;
        do {
            balance += s[j] == '(' ? 1 : -1;
            if (balance < 0)
                good = false;
            ++j;
        } while (j < n && balance != 0);
        if (!good)
            ans += j - i;
        i = j;
    }
    std::cout << ans << "\n";
    return 0;
}