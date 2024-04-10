#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
constexpr int P = 998'244'353;
struct Matrix {
    int a[2][2];
    Matrix() : a{} {}
};
Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    Matrix res;
    res.a[0][0] = (1LL * lhs.a[0][0] * rhs.a[0][0] + 1LL * lhs.a[0][1] * rhs.a[1][0]) % P;
    res.a[0][1] = (1LL * lhs.a[0][0] * rhs.a[0][1] + 1LL * lhs.a[0][1] * rhs.a[1][1]) % P;
    res.a[1][0] = (1LL * lhs.a[1][0] * rhs.a[0][0] + 1LL * lhs.a[1][1] * rhs.a[1][0]) % P;
    res.a[1][1] = (1LL * lhs.a[1][0] * rhs.a[0][1] + 1LL * lhs.a[1][1] * rhs.a[1][1]) % P;
    return res;
}
struct Frac {
    int x, y;
    Frac(int x, int y) : x(x), y(y) {}
};
bool operator<(const Frac &lhs, const Frac &rhs) {
    return 1LL * lhs.x * rhs.y < 1LL * lhs.y * rhs.x;
}
bool operator==(const Frac &lhs, const Frac &rhs) {
    return !(lhs < rhs) && !(rhs < lhs);
}
int n;
std::vector<int> x, v, p;
int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = 1LL * ans * a % P;
        a = 1LL * a * a % P;
        b >>= 1;
    }
    return ans;
}
constexpr int N = 100'000;
Matrix t[4 * N];
void pull(int p) {
    t[p] = t[2 * p] * t[2 * p + 1];
}
void build(int p, int l, int r) {
    if (r - l == 1) {
        t[p].a[0][0] = t[p].a[1][0] = (1 - ::p[l] + P) % P;
        t[p].a[0][1] = t[p].a[1][1] = ::p[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m, r);
    pull(p);
}
void modify(int p, int l, int r, int x, int a, int b) {
    if (r - l == 1) {
        t[p].a[a][b] = 0;
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        modify(2 * p, l, m, x, a, b);
    } else {
        modify(2 * p + 1, m, r, x, a, b);
    }
    pull(p);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    x.resize(n);
    v.resize(n);
    p.resize(n);
    int inv = power(100, P - 2);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> v[i] >> p[i];
        p[i] = 1LL * p[i] * inv % P;
    }
    std::vector<std::tuple<Frac, int, int, int>> event;
    build(1, 0, n);
    for (int i = 1; i < n; ++i) {
        event.emplace_back(Frac(x[i] - x[i - 1], v[i - 1] + v[i]), i, 1, 0);
        if (v[i] > v[i - 1])
            event.emplace_back(Frac(x[i] - x[i - 1], v[i] - v[i - 1]), i, 0, 0);
        if (v[i] < v[i - 1])
            event.emplace_back(Frac(x[i] - x[i - 1], v[i - 1] - v[i]), i, 1, 1);
    }
    std::sort(event.begin(), event.end());
    int ans = 0;
    int lst = 0;
    for (int i = 0; i < int(event.size()); ++i) {
        auto [tim, pos, a, b] = event[i];
        int pr = (t[1].a[0][0] + t[1].a[0][1]) % P;
        int tp = 1LL * tim.x * power(tim.y, P - 2) % P;
        ans = (ans + 1LL * (tp - lst) * pr) % P;
        lst = tp;
        modify(1, 0, n, pos, a, b);
    }
    int pr = (t[1].a[0][0] + t[1].a[0][1]) % P;
    ans = (ans - 1LL * lst * pr) % P;
    ans = (ans + P) % P;
    std::cout << ans << "\n";
    return 0;
}