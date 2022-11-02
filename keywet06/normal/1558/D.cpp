#include <bits/stdc++.h>

const int P = 998244353;

using int64 = long long;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template <class _Tp>
_Tp power(_Tp a, int b) {
    _Tp res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct node {
    int x;
    node(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    node operator-() const { return node(norm(P - x)); }
    node inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    node &operator*=(const node &rhs) {
        x = int64(x) * rhs.x % P;
        return *this;
    }
    node &operator+=(const node &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    node &operator-=(const node &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    node &operator/=(const node &rhs) { return *this *= rhs.inv(); }
    friend node operator*(const node &lhs, const node &rhs) {
        node res = lhs;
        res *= rhs;
        return res;
    }
    friend node operator+(const node &lhs, const node &rhs) {
        node res = lhs;
        res += rhs;
        return res;
    }
    friend node operator-(const node &lhs, const node &rhs) {
        node res = lhs;
        res -= rhs;
        return res;
    }
    friend node operator/(const node &lhs, const node &rhs) {
        node res = lhs;
        res /= rhs;
        return res;
    }
};

constexpr int N = 2E5;

int fen[N];

void add(int x, int y) {
    for (int i = x + 1; i <= N; i += i & -i) {
        fen[i - 1] += y;
    }
}

int find(int k) {
    int x = 0, s = 0;
    for (int i = 1 << 17; i > 0; i >>= 1) {
        if (x + i <= N && x + i - s - fen[x + i - 1] <= k) {
            x += i;
            s += fen[x - 1];
        }
    }
    return x;
}

node fac[2 * N + 1], invfac[2 * N + 1];

node binom(int n, int m) { return fac[n] * invfac[m] * invfac[n - m]; }

void solve() {
    int n, m;
    std::cin >> n >> m;

    int x[m], y[m];

    for (int i = 0; i < m; i++) {
        std::cin >> x[i] >> y[i];
        y[i]--;
    }

    std::set<int> s;

    for (int i = m - 1; i >= 0; i--) {
        s.insert(find(y[i] + 1));
        y[i] = find(y[i]);
        add(y[i], 1);
    }

    for (int i = 0; i < m; i++) {
        add(y[i], -1);
    }

    node res = binom(n + n - 1 - s.size(), n);

    std::cout << res.val() << "\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    fac[0] = 1;
    for (int i = 1; i <= 2 * N; i++) {
        fac[i] = fac[i - 1] * i;
    }
    invfac[2 * N] = fac[2 * N].inv();
    for (int i = 2 * N; i > 0; i--) {
        invfac[i - 1] = invfac[i] * i;
    }

    int T;
    std::cin >> T;

    while (T--) solve();

    return 0;
}