#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    std::vector<int> next(n, -1);
    std::vector<int> last(n, -1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    for (int i = n - 1; i >= 0; i--) {
        next[i] = last[a[i]];
        last[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i]--;
    }
    
    std::vector<int> cnt(n, 1);
    for (int i = 0, j = 0; i < n; i++) {
        while (a[j] != b[i] || cnt[j] == 0) {
            if (cnt[j] > 0) {
                if (next[j] == -1) {
                    std::cout << "NO\n";
                    return;
                }
                cnt[next[j]] += cnt[j];
                cnt[j] = 0;
            }
            j++;
        }
        cnt[j]--;
    }
    
    std::cout << "YES\n";
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