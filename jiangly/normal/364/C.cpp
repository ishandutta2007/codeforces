#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int k;
    std::cin >> k;
    
    std::vector<int> p{2, 3, 5, 7, 11};
    
    std::vector<int> a{1};
    for (auto x : p) {
        std::vector<int> b;
        for (i64 y : a) {
            while (y <= 2 * k * k) {
                b.push_back(y);
                y *= x;
            }
        }
        a = b;
        if (int(a.size()) >= k) {
            break;
        }
    }
    
    std::sort(a.begin(), a.end());
    for (int i = a.size() - k; i < int(a.size()); i++) {
        std::cout << a[i] << " \n"[i == int(a.size()) - 1];
    }
    
    return 0;
}