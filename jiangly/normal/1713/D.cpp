#include <bits/stdc++.h>

using i64 = long long;

int query(int a, int b) {
    std::cout << "? " << a + 1 << " " << b + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(1 << n);
    std::iota(a.begin(), a.end(), 0);
    
    while (a.size() >= 4) {
        std::vector<int> b;
        for (int i = 0; i < int(a.size()); i += 4) {
            int x = query(a[i], a[i + 2]);
            if (x == 0) {
                if (query(a[i + 1], a[i + 3]) == 1) {
                    b.push_back(a[i + 1]);
                } else {
                    b.push_back(a[i + 3]);
                }
            } else if (x == 1) {
                if (query(a[i], a[i + 3]) == 1) {
                    b.push_back(a[i]);
                } else {
                    b.push_back(a[i + 3]);
                }
            } else {
                if (query(a[i + 1], a[i + 2]) == 1) {
                    b.push_back(a[i + 1]);
                } else {
                    b.push_back(a[i + 2]);
                }
            }
        }
        a = b;
    }
    
    if (a.size() == 2) {
        if (query(a[0], a[1]) == 1) {
            a = {a[0]};
        } else {
            a = {a[1]};
        }
    }
    
    std::cout << "! " << a[0] + 1 << std::endl;
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