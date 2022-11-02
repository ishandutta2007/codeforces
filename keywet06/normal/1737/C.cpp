#include <bits/stdc++.h>

bool Main() {
    int n, r[3], c[3], x, y;
    std::cin >> n >> r[1] >> c[1] >> r[2] >> c[2] >> r[0] >> c[0] >> x >> y;
    int t = 0, p = -1;
    for (int i = 0; i < 3; ++i) {
        t += (r[i] == 1) + (r[i] == n) + (c[i] == 1) + (c[i] == n);
        if ((r[i] == 1) + (r[i] == n) + (c[i] == 1) + (c[i] == n) == 2) p = i;
    }
    if (t == 4) return r[p] == x || c[p] == y;
    for (int i = 0; i < 3; ++i) {
        if (!((r[i] ^ x) & 1) && !((c[i] ^ y) & 1)) return true;
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) std::cout << (Main() ? "YES" : "NO") << '\n';
    return 0;
}