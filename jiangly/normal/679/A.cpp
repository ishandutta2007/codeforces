#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int cnt = 0;
    for (auto x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49}) {
        std::cout << x << std::endl;
        std::string ans;
        std::cin >> ans;
        if (ans == "yes") {
            ++cnt;
        }
    }
    
    if (cnt >= 2) {
        std::cout << "composite" << std::endl;
    } else {
        std::cout << "prime" << std::endl;
    }
    
    return 0;
}