#include <bits/stdc++.h>

using i64 = long long;

struct Info {
    i64 pre;
    i64 suf;
    i64 ans;
    i64 sum;
    Info(i64 x = 0) : pre(std::max(0LL, x)), suf(std::max(0LL, x)), ans(std::max(0LL, x)), sum(x) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.pre = std::max(a.pre, a.sum + b.pre);
    c.suf = std::max(a.suf + b.sum, b.suf);
    c.ans = std::max({a.ans, b.ans, a.suf + b.pre});
    c.sum = a.sum + b.sum;
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<Info> a(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        int x;
        std::cin >> x;
        a[i] = x;
    }
    
    for (int i = 1; i < (1 << n); i *= 2) {
        for (int j = 0; j < (1 << n); j += 2 * i) {
            for (int k = 0; k < i; k++) {
                std::tie(a[j + k], a[i + j + k]) = std::pair(a[j + k] + a[i + j + k], a[i + j + k] + a[j + k]);
            }
        }
    }
    
    int cur = 0;
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int k;
        std::cin >> k;
        cur ^= 1 << k;
        std::cout << a[cur].ans << "\n";
    }
    
    return 0;
}