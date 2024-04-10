#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<i64> t(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i] >> w[i];
    }
    
    std::vector<int> p(n - 1);
    std::iota(p.begin(), p.end(), 1);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return t[i] > t[j]; });
    
    int ans = n;
    i64 left = t[0];
    std::priority_queue<i64> h;
    for (int i = 0, j = 0; ; i++) {
        while (j < n - 1 && t[p[j]] > left) {
            h.push(t[p[j]] - w[p[j]] - 1);
            j++;
        }
        ans = std::min(ans, j - i + 1);
        if (h.empty() || -h.top() > left) {
            break;
        }
        left += h.top();
        h.pop();
    }
    
    std::cout << ans << "\n";
    
    return 0;
}