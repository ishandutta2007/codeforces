#include <bits/stdc++.h>

using int64 = long long;

int T, n, l, r, mid;

int64 query(int l, int r) {
    int64 ret;
    std::cout << "? " << l << ' ' << r << std::endl;
    std::cin >> ret;
    return ret;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, l = 1, r = n;
        while (l < r) {
            mid = l + r >> 1;
            if (query(1, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        --l;
        mid = l + query(l, n) - query(l + 1, n) + 1;
        r = mid + query(mid, n) - query(mid + 1, n);
        std::cout << "! " << l << ' ' << mid << ' ' << r << std::endl;
    }
    return 0;
}