#include <bits/stdc++.h>

int main() {
    
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::cout << "? " << 2 << " " << 3 << std::endl;
    std::cin >> a[0];
    for (int i = 1; i < n; ++i) {
        std::cout << "? " << 1 << " " << i + 1 << std::endl;
        std::cin >> a[i];
    }
    a[0] = a[2] - a[0];
    std::adjacent_difference(a.begin(), a.end(), b.begin());
    std::cout << "!";
    for (int i = 0; i < n; ++i) std::cout << " " << b[i];
    std::cout << std::endl;
    
    return 0;
}