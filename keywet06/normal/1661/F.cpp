#include <bits/stdc++.h>

using int64 = long long;

int64 Get(int64 l, int64 k) {
    int64 v = l / (k + 1), c = l % (k + 1);
    return v * v * (k + 1 - c) + (v + 1) * (v + 1) * c;
}

const int N = 200005;

int n;
int a[N];

int64 m;

std::pair<int64, int64> Solve(int64 x) {
    int64 cx = 0, cy = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = a[i + 1] - a[i] - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (Get(a[i + 1] - a[i], m - 1) - Get(a[i + 1] - a[i], m) >= x) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        cx += l;
        cy += Get(a[i + 1] - a[i], l);
    }
    return std::pair<int64, int64>(cx, cy);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::cin >> m;
    int64 vl = 0, vr = 1E18;
    while (vr - vl > 1) {
        int64 x = (vl + vr) / 2;
        auto [cx, cy] = Solve(x);
        if (cy > m) {
            vr = x;
        } else {
            vl = x;
        }
    }
    auto [cx, cy] = Solve(vr);
    std::cout << cx + (cy - m + vl - 1) / vl << "\n";
    return 0;
}