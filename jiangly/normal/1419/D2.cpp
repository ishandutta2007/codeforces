#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    
    std::sort(a.begin(), a.end());
    
    std::vector<int> b(n);
    int cur = 0;
    for (int i = 1; i < n; i += 2)
        b[i] = a[cur++];
    for (int i = 0; i < n; i += 2)
        b[i] = a[cur++];
    
    int ans = 0;
    for (int i = 1; i < n - 1; ++i)
        ans += b[i] < b[i - 1] && b[i] < b[i + 1];
    
    std::cout << ans << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << b[i] << " \n"[i == n - 1];
    
    return 0;
}