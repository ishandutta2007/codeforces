#include <bits/stdc++.h>

const int N = 500005;

inline int Next1(int u1, int u2, int x) { return std::min(u1 < x ? u2 : INT_MAX, u2 < x ? u1 : INT_MAX); }
inline int Next2(int la, int c2, int c3, int x) { return std::min(x < la ? c2 : INT_MAX, x < c3 ? la : INT_MAX); }
inline int Next3(int la, int c2, int c3, int x) { return std::max(x > la ? c3 : 0, x > c2 ? la : 0); }

int n, p;
int a[N], f1[N], f2[N], f3[N], g1[N], g2[N], g3[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n, p = 0;
    for (int i = 1; i <= n; ++i) std::cin >> a[i], p = a[i] > a[p] ? i : p;
    for (int i = 1; i <= p; ++i) f1[i] = Next1(a[i - 1], f1[i - 1], a[i]);
    for (int i = n; i >= p; --i) g1[i] = Next1(a[i + 1], g1[i + 1], a[i]);
    f2[p] = f1[p], f3[p] = 0;
    for (int i = p + 1; i <= n; ++i) {
        f2[i] = Next2(a[i - 1], f2[i - 1], f3[i - 1], a[i]);
        f3[i] = Next3(a[i - 1], f2[i - 1], f3[i - 1], a[i]);
    }
    g2[p] = g1[p], g3[p] = 0;
    for (int i = p - 1; i >= 1; --i) {
        g2[i] = Next2(a[i + 1], g2[i + 1], g3[i + 1], a[i]);
        g3[i] = Next3(a[i + 1], g2[i + 1], g3[i + 1], a[i]);
    }
    int Ans = 0;
    for (int i = 1; i < p; ++i) Ans += g3[i] > f1[i];
    for (int i = p + 1; i <= n; ++i) Ans += f3[i] > g1[i];
    std::cout << Ans << '\n';
    return 0;
}