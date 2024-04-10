#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n1, n2;
    std::cin >> n1 >> n2;
    if (n1 > n2) {
        std::cout << "First\n";
    } else {
        std::cout << "Second\n";
    }
    return 0;
}