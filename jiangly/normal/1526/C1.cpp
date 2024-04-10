#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::priority_queue<int> h;
    i64 cur = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            ans++;
            cur += a[i];
        } else {
            if (cur + a[i] >= 0) {
                ans++;
                cur += a[i];
                h.push(-a[i]);
            } else if (!h.empty() && -a[i] < h.top()) {
                cur += a[i] + h.top();
                h.pop();
                h.push(-a[i]);
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}