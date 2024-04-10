#include <bits/stdc++.h>

using i64 = long long;

constexpr int M = 4E6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> R(M + 1, M + 1), L(M + 1);
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        R[a[i]] = a[i];
        L[a[i]] = a[i];
    }
    for (int i = M - 1; i > 0; i--) {
        R[i] = std::min(R[i], R[i + 1]);
    }
    for (int i = 1; i <= M; i++) {
        L[i] = std::max(L[i], L[i - 1]);
    }
    
    i64 ans = 1E18;
    for (int x = 1; x <= M; x++) {
        if (a[0] > 1LL * x * x + x) {
            continue;
        }
        i64 l = 0, r = 1E18;
        int last = -1;
        for (int i = 0; ; i++) {
            int y = 1LL * (x + i) * (x + i) - 1LL * x * x - x + a[0];
            y = std::max(y, a[0]);
            if (y > a[n - 1]) {
                l = std::max(l, 1LL * (x + i - 1) * (x + i - 1) - last);
                int u = a[n - 1];
                r = std::min(r, 1LL * (x + i - 1) * (x + i) - u);
                break;
            }
            int v = R[y];
            if (i > 0 && v != last) {
                l = std::max(l, 1LL * (x + i - 1) * (x + i - 1) - last);
                int u = L[v - 1];
                r = std::min(r, 1LL * (x + i - 1) * (x + i) - u);
            }
            last = v;
        }
        if (l <= r) {
            ans = std::min(ans, l);
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}