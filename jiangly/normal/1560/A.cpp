#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> res;
    
    for (int x = 1; res.size() < 1000; x++) {
        if (x % 3 != 0 && x % 10 != 3) {
            res.push_back(x);
        }
    }
    
    int t;
    std::cin >> t;
    while (t--) {
        int k;
        std::cin >> k;
        std::cout << res[k - 1] << "\n";
    }
    
    return 0;
}