#include <bits/stdc++.h>
const int N = 120005;
const int R = 10005;
const int Si = 1700;
const int Sn = 60;
const int A = 30;
const int lucky[] = {4,    7,    44,   47,   74,   77,   444,  447,
                     474,  477,  744,  747,  774,  777,  4444, 4447,
                     4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447,
                     7474, 7477, 7744, 7747, 7774, 7777};
int n, m, l, r, d, ans, t;
int a[N];
int is[R];
int plus[Sn];
int z[Sn][R];
std::string opt;
inline int id(int x) { return x / Si; }
inline int be(int x) { return x * Si; }
inline int en(int x) { return std::min(x * Si + Si, n); }
inline int begins(int x) { return be(id(x)); }
inline int ends(int x) { return en(id(x)); }
inline void build(int x, int v) {
    for (int i = be(x); i < en(x); ++i) z[x][a[i]] += v;
}
inline void push(int x) {
    build(x, -1);
    for (int i = be(x); i < en(x); ++i) a[i] += plus[x];
    plus[x] = 0;
    build(x, 1);
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    for (int i = 0; i < A; ++i) is[lucky[i]] = 1;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i <= id(n - 1); ++i) build(i, 1);
    while (m--) {
        std::cin >> opt >> l >> r;
        push(id(--l)), push(id(--r));
        if (opt == std::string("count")) {
            ans = 0;
            if (id(l) == id(r)) {
                for (int i = l; i <= r; ++i) ans += is[a[i]];
                std::cout << ans << '\n';
                continue;
            }
            for (int i = l; i < ends(l); ++i) ans += is[a[i]];
            for (int i = begins(r); i <= r; ++i) ans += is[a[i]];
            for (int i = id(l) + 1; i < id(r); ++i) {
                for (int j = 0; j < A; ++j) {
                    t = lucky[j] - plus[i];
                    if (0 < t && t < R) ans += z[i][t];
                }
            }
            std::cout << ans << '\n';
        } else {
            std::cin >> d;
            if (id(l) == id(r)) {
                build(id(l), -1);
                for (int i = l; i <= r; ++i) a[i] += d;
                build(id(l), 1);
                continue;
            }
            build(id(l), -1), build(id(r), -1);
            for (int i = l; i < ends(l); ++i) a[i] += d;
            for (int i = begins(r); i <= r; ++i) a[i] += d;
            build(id(l), 1), build(id(r), 1);
            for (int i = id(l) + 1; i < id(r); ++i) plus[i] += d;
        }
    }
    return 0;
}