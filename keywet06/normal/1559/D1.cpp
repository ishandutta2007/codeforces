#include <bits/stdc++.h>

#define Deb std::cerr
#define Debug Deb << "Debug(" << __LINE__ << "): "
#define fi first
#define se second
#define mkp std::make_pair

using int32 = int;
using int64 = long long;
using i3 = int32;
using i4 = int64;
using pi33 = std::pair<i3, i3>;
using pi34 = std::pair<i3, i4>;
using pi43 = std::pair<i4, i3>;
using pi44 = std::pair<i4, i4>;

const int N = 1000005;

int T, n, m1, m2, k, x, y, z, ans;
int f1[N], f2[N];

inline int find1(int x) { return f1[x] == x ? x : (f1[x] = find1(f1[x])); }
inline int find2(int x) { return f2[x] == x ? x : (f2[x] = find2(f2[x])); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; ++i) f1[i] = f2[i] = i;
    for (int i = 1; i <= m1; ++i) {
        std::cin >> x >> y, f1[find1(x)] = find1(y);
    }
    for (int i = 1; i <= m2; ++i) {
        std::cin >> x >> y, f2[find2(x)] = find2(y);
    }
    std::cout << (ans = std::max(n - std::max(m1, m2) - 1, 0)) << std::endl;
    while (ans--) {
        x = 0;
        for (int i = 2; i <= n; ++i) {
            if (find1(i) != find1(1)) y = i;
            if (find1(i) != find1(1) && find2(i) != find2(1)) {
                std::cout << 1 << ' ' << i << '\n';
                f1[find1(i)] = find1(1);
                f2[find2(i)] = find2(1);
                x = 1;
                break;
            }
        }
        if (x) continue;
        for (int i = 2; i <= n; ++i) {
            if (find2(i) != find2(1)) {
                std::cout << i << ' ' << y << '\n';
                f1[find1(i)] = find1(y);
                f2[find2(i)] = find2(y);
                break;
            }
        }
    }
    return 0;
}