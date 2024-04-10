#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;

constexpr int V = 1 << 19;

int cnt[2 * V], mn[4 * V], c[4 * V];

void build(int p, int l, int r) {
    mn[p] = l - V;
    if (r - l == 1) {
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m, r);
}

void modify(int p, int l, int r, int x) {
    c[p]++;
    if (r - l == 1) {
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        modify(2 * p, l, m, x);
    } else {
        modify(2 * p + 1, m, r, x);
    }
    mn[p] = std::min(mn[2 * p] + c[2 * p + 1], mn[2 * p + 1]);
}

int query(int p, int l, int r, int x) {
    if (r <= x) {
        return 1e9;
    }
    if (l >= x) {
        return mn[p];
    }
    int m = (l + r) / 2;
    return std::min(query(2 * p, l, m, x) + c[2 * p + 1], query(2 * p + 1, m, r, x));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    build(1, 0, 2 * V);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int dec = 0, sum = 0;
    
    for (int i = 0; i < n; i++) {
        cnt[a[i] + V]++;
        if (a[i] <= -dec) {
            sum++;
            if (sum - cnt[-dec + V] > dec) {
                sum -= cnt[-dec + V];
                dec++;
            }
        }
        modify(1, 0, 2 * V, a[i] + V);
        std::cout << query(1, 0, 2 * V, -dec + V) << "\n";
    }
    
    return 0;
}