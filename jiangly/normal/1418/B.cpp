#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        
        std::vector<int> l(n), unlock;
        for (int i = 0; i < n; ++i) {
            std::cin >> l[i];
            if (l[i] == 0)
                unlock.push_back(a[i]);
        }
        
        std::sort(unlock.begin(), unlock.end(), std::greater<>());
        
        for (int i = 0, j = 0; i < n; ++i)
            if (l[i] == 0)
                a[i] = unlock[j++];
        
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
    }
    
    return 0;
}