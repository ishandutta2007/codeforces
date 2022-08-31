#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto b = a;
    
    std::sort(a.begin(), a.end());
    
    int L = 1, R = n;
    for (int i = 0, j = 0; i < n; i++) {
        while (j <= n && j - i - (n - j + i) < k) {
            j++;
        }
        if (j <= n && a[j - 1] - a[i] < R - L) {
            L = a[i];
            R = a[j - 1];
        }
    }
    
    int s = 0;
    int c = 1;
    int l = 0;
    std::cout << L << " " << R << "\n";
    for (int i = 0; i < n; i++) {
        s += (L <= b[i] && b[i] <= R) ? 1 : -1;
        if (c == k ? i == n - 1 : s == c) {
            std::cout << l + 1 << " " << i + 1 << "\n";
            l = i + 1;
            c++;
        }
    }
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