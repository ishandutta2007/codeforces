#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int query(int a, int b, int c) {
    std::cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int a, b, c;
        do {
            a = rnd() % n;
            do {
                b = rnd() % n;
            } while (a == b);
            do {
                c = rnd() % n;
            } while (a == c || b == c);
        } while (query(a, b, c) >= n / 6);
        std::vector<int> v(n);
        for (int i = 0; i < n; i++) {
            if (i != a && i != b) {
                v[i] = query(a, b, i);
            }
        }
        int u0 = std::max_element(v.begin(), v.end()) - v.begin();
        int u1 = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] + 1 == v[u0] && (query(u0, i, a) == v[i] || query(u0, i, b) == v[i])) {
                u1 = i;
            }
        }
        std::vector<int> p(n, -1);
        p[u0] = 0;
        p[u1] = 1;
        for (int i = 0; i < n; i++) {
            if (p[i] == -1) {
                p[i] = 1 + query(u0, u1, i);
            }
        }
        if (p[0] > p[1]) {
            for (int i = 0; i < n; i++) {
                p[i] = n - 1 - p[i];
            }
        }
        std::cout << "!";
        for (int i = 0; i < n; i++) {
            std::cout << " " << p[i] + 1;
        }
        std::cout << std::endl;
        int ans;
        std::cin >> ans;
    }
    return 0;
}