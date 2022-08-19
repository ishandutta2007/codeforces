#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int a[n], p[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        p[a[i]] = i;
    }
    
    int res[n];
    for (int i = 0, j = n, l = 0, r = n; i < n; i++) {
        if (p[i] > j) {
            continue;
        }
        res[l++] = i;
        for (int t = j - 1; t > p[i]; t--) {
            res[--r] = a[t];
        }
        j = p[i];
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << res[i] + 1 << " \n"[i == n - 1];
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