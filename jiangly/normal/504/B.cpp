#include <bits/stdc++.h>
using i64 = long long;
struct Fenwick {
    const int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    int sum(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    int rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    int find(int k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i > 0; i /= 2) {
            if (x + i <= n && a[x + i - 1] <= k) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> q[i];
    }
    Fenwick f1(n), f2(n), f3(n);
    for (int i = 0; i < n; i++) {
        f3.add(i, 1);
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] += p[i] - f1.sum(p[i]);
        a[i] += q[i] - f2.sum(q[i]);
        f1.add(p[i], 1);
        f2.add(q[i], 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] >= n - i) {
            a[i] -= n - i;
            if (i > 0) {
                a[i - 1]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int x = f3.find(a[i]);
        f3.add(x, -1);
        std::cout << x << " \n"[i == n - 1];
    }
    return 0;
}