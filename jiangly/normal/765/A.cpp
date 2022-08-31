#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    if (n % 2 == 1) {
        std::cout << "contest\n";
    } else {
        std::cout << "home\n";
    }
    
    return 0;
}