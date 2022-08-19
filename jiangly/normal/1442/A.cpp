#include <bits/stdc++.h>
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = n; i; --i) a[i] -= a[i - 1];
        int pos = 0, neg = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > 0) pos += a[i];
            else neg += -a[i];
        }
        if (a[0] >= neg && -a[n] >= pos) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    
    return 0;
}