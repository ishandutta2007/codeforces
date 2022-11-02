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

std::queue<int> q, q1, q2;

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
    for (int i = 1; i <= n; ++i) q1.push(i), q2.push(i), q.push(i);
    while (ans--) {
        x = 0;
        while (find1(q1.front()) == find1(1)) q1.pop();
        while (find2(q2.front()) == find2(1)) q2.pop();
        while (!q.empty() &&
               (find1(q.front()) == find1(1) || find2(q.front()) == find2(1))) {
            q.pop();
        }
        if (!q.empty()) {
            z = q.front(), q.pop();
            std::cout << 1 << ' ' << z << '\n';
            f1[find1(z)] = find1(1);
            f2[find2(z)] = find2(1);
        } else {
            x = q1.front(), q1.pop();
            y = q2.front(), q2.pop();
            std::cout << x << ' ' << y << '\n';
            f1[find1(x)] = find1(y);
            f2[find2(x)] = find2(y);
        }
    }
    return 0;
}