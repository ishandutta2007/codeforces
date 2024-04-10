#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::string s;
std::vector<int> so, sc;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> s;
    n = s.length();
    so.resize(n + 1);
    sc.resize(n + 1);
    for (int i = 0; i < n; ++i)
        so[i + 1] = so[i] + (s[i] == '(');
    for (int i = n - 1; i >= 0; --i)
        sc[i] = sc[i + 1] + (s[i] == ')');
    for (int i = 0; i <= n; ++i) {
        if (so[i] == 0 && sc[i] == 0) {
            std::cout << 0 << "\n";
            return 0;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (so[i] == sc[i]) {
            std::cout << 1 << "\n";
            std::cout << 2 * so[i] << "\n";
            for (int j = 0; j < i; ++j)
                if (s[j] == '(')
                    std::cout << j + 1 << " ";
            for (int j = i; j < n; ++j)
                if (s[j] == ')')
                    std::cout << j + 1 << " ";
            std::cout << "\n";
            return 0;
        }
    }
}