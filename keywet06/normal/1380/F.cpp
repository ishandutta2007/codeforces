#include <bits/stdc++.h>

using int64 = long long;

const int B = 2;
const int P = 998244353;

struct mat {
    int64 a[B][B];
    mat() { memset(a, 0, sizeof(a)); }
    mat(int x) { a[0][1] = a[1][1] = 0, a[0][0] = 1, a[1][0] = x + 1; }
    mat(int x, int y) {
        a[0][1] = 1, a[1][1] = y + 1, a[0][0] = 0, a[1][0] = x == 1 ? 9 - y : 0;
    }
    int64 *operator[](size_t x) { return a[x]; }
};

inline mat operator*(mat x, mat y) {
    mat ret;
    ret[0][0] = (x[0][0] * y[0][0] + x[0][1] * y[1][0]) % P;
    ret[0][1] = (x[0][0] * y[0][1] + x[0][1] * y[1][1]) % P;
    ret[1][0] = (x[1][0] * y[0][0] + x[1][1] * y[1][0]) % P;
    ret[1][1] = (x[1][0] * y[0][1] + x[1][1] * y[1][1]) % P;
    return ret;
}

const int N = 500005;
const int M = 1048576;

int a[N];

mat sum[M];

inline void build(int u, int l, int r) {
    if (l == r) return void(sum[u] = mat(a[l - 1], a[r]));
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    sum[u] = sum[u << 1 | 1] * sum[u << 1];
}

inline void update(int u, int l, int r, int x) {
    if (l == r) return void(sum[u] = mat(a[l - 1], a[r]));
    int mid = l + r >> 1;
    if (x <= mid) update(u << 1, l, mid, x);
    if (x >= mid) update(u << 1 | 1, mid + 1, r, x);
    sum[u] = sum[u << 1 | 1] * sum[u << 1];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int n, q, x, y;
    std::string s;
    std::cin >> n >> q >> s;
    for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
    if (n == 1) {
        while (q--) std::cin >> x >> y, std::cout << y + 1 << '\n';
        return 0;
    }
    build(1, 1, n - 1);
    while (q--) {
        std::cin >> x >> y, a[--x] = y, update(1, 1, n - 1, x);
        std::cout << (sum[1] * a[0])[1][0] << '\n';
    }
    return 0;
}