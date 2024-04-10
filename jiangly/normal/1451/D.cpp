#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t d, k;
        std::cin >> d >> k;
        int64_t x = 0;
        while ((x + k) * (x + k) * 2 <= d * d) x += k;
        if (x * x + (x + k) * (x + k) <= d * d) {
            std::cout << "Ashish\n";
        } else {
            std::cout << "Utkarsh\n";
        }
    }
    
    return 0;
}