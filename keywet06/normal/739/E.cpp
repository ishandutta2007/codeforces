#include <bits/stdc++.h>

using ldou = long double;

const int T = 40;
const int N = 2010;
const ldou INF = 1e5;

ldou u[N], v[N], q[N], L, R;
int n, a, b;

struct node {
    ldou val;
    int a, b;
    node(ldou V = 0, int A = 0, int B = 0) { val = V, a = A, b = B; }
    inline bool operator<(const node &o) const { return val < o.val; }
    inline node operator+(const node &o) const {
        return node(val + o.val, a + o.a, b + o.b);
    }
} dp[N];

inline void check_agn(ldou x, ldou y) {
    dp[0] = node();
    for (int i = 1; i <= n; ++i) {
        dp[i] = node(-INF, 0, 0);
        dp[i] =
            std::max(std::max(dp[i - 1], dp[i - 1] + node(q[i] - x - y, 1, 1)),
                     std::max(dp[i - 1] + node(u[i] - x, 1, 0),
                              dp[i - 1] + node(v[i] - y, 0, 1)));
    }
}

inline void check(ldou v) {
    L = 0, R = 1;
    for (int i = 1; i <= T; ++i) {
        ldou mid = (L + R) / 2;
        check_agn(v, mid);
        (dp[n].b >= b ? L : R) = mid;
    }
    check_agn(v, L);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) std::cin >> u[i];
    for (int i = 1; i <= n; ++i) std::cin >> v[i];
    for (int i = 1; i <= n; ++i) q[i] = u[i] + v[i] - u[i] * v[i];
    ldou l = 0, r = 1;
    for (int i = 1; i <= T; ++i) {
        ldou mid = (l + r) / 2;
        check(mid);
        (dp[n].a >= a ? l : r) = mid;
    }
    check(l);
    std::cout << dp[n].val + l * a + L * b << std::endl;
    return 0;
}