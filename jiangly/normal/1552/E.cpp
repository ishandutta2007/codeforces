#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    int lim = (n + k - 2) / (k - 1);
    
    std::vector<int> c(n * k);
    int lst = 0;
    for (int i = 0; i < n * k; i++) {
        std::cin >> c[i];
        c[i]--;
    }
    
    std::vector<int> a(n, -1), b(n);
    
    int cur = 0;
    std::vector<int> pre(n, -1);
    for (int i = 0; i < n * k; i++) {
        if (a[c[i]] >= 0) {
            continue;
        }
        if (pre[c[i]] >= lst) {
            a[c[i]] = pre[c[i]];
            b[c[i]] = i;
            cur++;
            if (cur == lim) {
                lst = i + 1;
                cur = 0;
            }
        }
        pre[c[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << a[i] + 1 << " " << b[i] + 1 << "\n";
    }
    
    return 0;
}