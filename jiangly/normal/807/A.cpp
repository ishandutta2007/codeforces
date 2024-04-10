#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int lst = 1e9;
    
    bool unr = false;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        if (a != b) {
            std::cout << "rated\n";
            return 0;
        }
        
        if (a > lst) {
            unr = true;
        }
        
        lst = a;
    }
    
    if (unr) {
        std::cout << "unrated\n";
    } else {
        std::cout << "maybe\n";
    }
    
    return 0;
}