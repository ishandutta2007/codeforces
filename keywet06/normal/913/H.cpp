#include <bits/stdc++.h>

using int64 = long long;

namespace oct {

void sync();

inline void ios() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}

}  // namespace oct

const int P = 998244353;

inline void add(int &a, int b) {
    a += b;
    if (a >= P) a -= P;
}

inline void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += P;
}

inline int mul(int a, int b) { return (int)((long long)a * b % P); }

inline int power(int a, long long b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a) { return power(a, P - 2); }

const int N = 77;

int C[N][N];

typedef std::vector<int> poly;

inline poly it(poly a) {
    poly b = {0};
    for (int i = 0; i < (int)a.size(); i++) b.push_back(mul(a[i], inv(i + 1)));
    return b;
}
void sub(poly &a, poly b) {
    while (a.size() < b.size()) a.push_back(0);
    for (int i = 0; i < (int)b.size(); i++) sub(a[i], b[i]);
}

poly pg(poly a, int delta) {
    poly b(a.size(), 0);
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j <= i; j++) {
            add(b[j], mul(a[i], mul(C[i][j], power(delta, i - j))));
        }
    }
    return b;
}

int gt(poly a, int x) {
    int res = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        res = mul(res, x),
        add(res, a[i]);
    }
    return res;
}

const int COEFF = 1000000;

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] =
                (j == 0 ? 1
                        : (i == 0 ? 0 : (C[i - 1][j] + C[i - 1][j - 1]) % P));
        }
    }
    int n;
    std::cin >> n;
    std::vector<int> x(n), fracs;
    for (int i = 0; i < n; i++) {
        double foo;
        std::cin >> foo;
        x[i] = (int)(foo * COEFF + 0.5);
        fracs.push_back(x[i] % COEFF);
    }
    fracs.push_back(0);
    std::sort(fracs.begin(), fracs.end());
    fracs.resize(std::unique(fracs.begin(), fracs.end()) - fracs.begin());
    int c = (int)fracs.size();
    std::vector<int> point(n * c + 1);
    for (int i = 0; i <= n * c; i++) {
        point[i] = mul(i / c * COEFF + fracs[i % c], inv(COEFF));
    }
    std::vector<int> cut(n);
    for (int i = 0; i < n; i++) {
        cut[i] = (int)(find(point.begin(), point.end(), mul(x[i], inv(COEFF))) -
                       point.begin());
    }
    std::vector<poly> a(n * c);
    for (int i = 0; i < n * c; i++) a[i] = {i < std::min(c, cut[0]) ? 1 : 0};
    for (int id = 1; id < n; id++) {
        for (int i = 0; i < n * c; i++) a[i] = it(a[i]);
        for (int i = n * c - 1; i >= 0; i--) {
            sub(a[i][0], gt(a[i], point[i]));
            for (int j = i - 1; j >= i - c && j >= 0; j--) {
                add(a[i][0], gt(a[j], point[j + 1]));
                if (j > i - c) {
                    sub(a[i][0], gt(a[j], point[j]));
                } else {
                    sub(a[i], pg(a[i - c], P - 1));
                }
            }
        }
        for (int i = cut[id]; i < n * c; i++) {
            a[i] = {0};
        }
    }
    int ans = 0;
    for (int i = 0; i < n * c; i++) {
        poly b = it(a[i]);
        add(ans, gt(b, point[i + 1]));
        sub(ans, gt(b, point[i]));
    }
    std::cout << ans << '\n';
    return 0;
}