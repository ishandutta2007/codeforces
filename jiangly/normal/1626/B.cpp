#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int n = s.length();
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    
    int i = n - 2;
    while (i >= 0 && a[i] + a[i + 1] < 10) {
        i--;
    }
    
    if (i >= 0) {
        a[i + 1] = a[i] + a[i + 1] - 10;
        a[i] = 1;
    } else {
        a[1] += a[0];
        a.erase(a.begin());
    }
    
    for (auto x : a) {
        std::cout << x;
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}