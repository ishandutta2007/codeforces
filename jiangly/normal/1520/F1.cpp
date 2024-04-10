#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int query(int l, int r) {
    int ans;
    std::cout << "? " << l + 1 << " " << r << std::endl;
    std::cin >> ans;
    return r - l - ans;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, t, k;
    std::cin >> n >> t >> k;
    int l = 0, r = n;
    k--;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (query(0, m) <= k) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << "! " << r << std::endl;
    return 0;
}