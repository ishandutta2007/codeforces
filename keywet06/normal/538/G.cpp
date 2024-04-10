#include <bits/stdc++.h>

template <typename Type1, typename Type2>
inline Type1 &Mid(Type1 &x, Type2 y) {
    return x < y ? x : (x = y);
}

template <typename Type1, typename Type2>
inline Type1 &Mad(Type1 &x, Type2 y) {
    return x > y ? x : (x = y);
}

using int64 = long long;

const int N = 200005;
const int M = 2000005;
const int64 INF64 = 1e17;

struct node {
    int64 w, c, x, y;
    node() {}
    node(int64 W, int64 C, int64 X, int64 Y) : w(W), c(C), x(X), y(Y) {}
};

inline bool operator<(const node x, const node y) { return x.w < y.w; }

inline int64 Floor(int64 x, int64 y) {
    return x >= 0 ? x / y : -(-x + y - 1) / y;
}

inline int64 Ceil(int64 x, int64 y) {
    return x >= 0 ? (x + y - 1) / y : -(-x / y);
}

const char D[2][3] = {"LU", "DR"};

int n, l;
int rx[M], ry[M];

int64 t, x, y;
int64 pw[N], pc[N], px[N], py[N];

node nd[N];

inline int Solve(int64 *A, int *Ret) {
    int64 *W = pw, *C = pc, r = l, l = 0;
    for (int i = 1, j = 2; i < n; ++i, ++j) {
        int64 k = C[i] - C[j], d, w = W[j] - W[i], L = A[i] - A[j], R = L + w;
        if (k == 0) {
            if (L > 0 || R < 0) return true;
        } else if (k > 0) {
            Mad(l, Ceil(L, k)), Mid(r, Floor(R, k));
        } else {
            Mad(l, Ceil(-R, -k)), Mid(r, Floor(-L, -k));
        }
    }
    if (l > r) return true;
    int64 &T = l;
    for (int i = 1, j = 2; i < n; ++i, ++j) {
        int U = W[i], S = (C[i] - C[j]) * T + (A[j] - A[i]);
        for (int j = 0; j < S; ++j) Ret[U + j] = 1;
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        std::cin >> t >> x >> y;
        if ((x + y + t) & 1) return std::cout << "NO" << '\n', 0;
        nd[i] = node(t % l, t / l, (x - y + t) / 2, (x + y + t) / 2);
    }
    nd[++n] = node(0, 0, 0, 0);
    nd[++n] = node(l, -1, 0, 0);
    std::sort(nd + 1, nd + n + 1);
    for (int i = 1; i <= n; ++i) {
        pw[i] = nd[i].w, pc[i] = nd[i].c, px[i] = nd[i].x, py[i] = nd[i].y;
    }
    if (Solve(px, rx) || Solve(py, ry)) return std::cout << "NO" << '\n', 0;
    for (int i = 0; i < l; ++i) std::cout << D[rx[i]][ry[i]];
    std::cout << '\n';
    return 0;
}