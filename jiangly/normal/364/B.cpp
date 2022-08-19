#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, d;
    std::cin >> n >> d;
    
    std::bitset<500001> f;
    f[0] = 1;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        f |= f << c;
        sum += c;
    }
    
    int cur = 0, days = 0, j = 0;
    for (int i = 1; i <= sum; i++) {
        if (i > cur + d) {
            if (j > cur) {
                cur = j;
                days++;
            } else {
                break;
            }
        }
        if (f[i]) {
            j = i;
        }
    }
    if (j > cur) {
        cur = j;
        days++;
    }
    
    std::cout << cur << " " << days << "\n";
    
    return 0;
}