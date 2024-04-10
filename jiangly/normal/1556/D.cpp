#include <bits/stdc++.h>

using i64 = long long;

int main() {
    
    int n, k;
    std::cin >> n >> k;
    k--;
    
    int o[n], a[n];
    for (int i = 1; i < n; i++) {
        std::cout << "or 1 " << i + 1 << std::endl;
        std::cin >> o[i];
        std::cout << "and 1 " << i + 1 << std::endl;
        std::cin >> a[i];
    }
    
    int o0, a0;
    std::cout << "or 2 3" << std::endl;
    std::cin >> o0;
    std::cout << "and 2 3" << std::endl;
    std::cin >> a0;
    
    int v[n];
    v[0] = 0;
    for (int i = 0; i < 30; i++) {
        int x = -1;
        for (int j = 1; j < n; j++) {
            if (~o[j] >> i & 1) {
                x = 0;
            }
            if (a[j] >> i & 1) {
                x = 1;
            }
        }
        if (x == -1) {
            x = ~o0 >> i & 1;
        }
        v[0] |= x << i;
    }
    for (int i = 1; i < n; i++) {
        v[i] = v[0] ^ a[i] ^ o[i];
    }
    
    std::sort(v, v + n);
    std::cout << "finish " << v[k] << std::endl;
    
    return 0;
}