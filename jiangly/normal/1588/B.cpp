#include <bits/stdc++.h>

using i64 = long long;

i64 query(int l, int r) {
    std::cout << "? " << l + 1 << " " << r << std::endl;
    i64 x;
    std::cin >> x;
    return x;
}

void solve() {
    int n;
    std::cin >> n;
    
    auto all = query(0, n);
    
    int l = 0, r = n;
    int k = -1;
    i64 cnt = -1;
    while (true) {
        int m = (l + r) / 2;
        i64 res = query(0, m);
        if (res != 0 && res != all) {
            k = m;
            cnt = res;
            break;
        }
        if (res == 0) {
            l = m;
        } else {
            r = m;
        }
    }
    
    auto dif = cnt - query(0, k - 1);
    
    int a, b, c;
    if (cnt == 1LL * dif * (dif + 1) / 2) {
        a = k - 1 - dif;
        dif = query(k - 1, n) - query(k, n);
        b = k + dif;
        c = b + query(b, n) - query(b + 1, n) + 1;
    } else {
        b = k - 1 - dif;
        dif = query(k - 1, n) - query(k, n);
        c = k + dif;
        a = b - (query(0, b) - query(0, b - 1) + 1);
    }
    
    std::cout << "! " << a + 1 << " " << b + 1 << " " << c << std::endl;
}

int main() {
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}