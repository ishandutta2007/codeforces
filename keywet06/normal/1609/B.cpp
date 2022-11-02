#include <bits/stdc++.h>

template <typename _Tp>
inline _Tp &mid(_Tp &x, _Tp y) {
    return x < y ? x : (x = y);
}

template <typename _Tp>
inline _Tp min(_Tp x, _Tp y) {
    return x < y ? x : y;
}

template <typename _Tp, typename... Args>
inline _Tp min(_Tp x, _Tp y, Args... args) {
    return min(min(x, y), args...);
}

using int64 = long long;

const int C = 3;
const int N = 100005;
const int M = 262144;
const int INF = N;

struct mat {
    int64 a[C][C];
    mat() {
        a[0][0] = a[0][1] = a[0][2] = INF;
        a[1][0] = a[1][1] = a[1][2] = INF;
        a[2][0] = a[2][1] = a[2][2] = INF;
    }
    mat(char ch) {
        a[0][0] = ch == 'a', a[0][1] = ch != 'c', a[0][2] = ch != 'b';
        a[1][0] = ch != 'a', a[1][1] = ch != 'a', a[1][2] = ch != 'a';
        a[2][0] = INF, a[2][1] = ch != 'b', a[2][2] = INF;
    }
    inline int64 *operator[](size_t x) { return a[x]; }
};

inline mat operator*(mat x, mat y) {
    mat ret;
    for (register int i = 0; i < C; ++i) {
        for (register int k = 0; k < C; ++k) {
            for (register int j = 0; j < C; ++j) {
                mid(ret[i][j], x[i][k] + y[k][j]);
            }
        }
    }
    return ret;
}

char ch;

int n, q, x;

mat base, t;
mat sum[M];

std::string s;

inline void build(int u, int l, int r) {
    if (l == r) return void(sum[u] = s[l]);
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    sum[u] = sum[u << 1 | 1] * sum[u << 1];
}

inline void update(int u, int l, int r, int x) {
    if (l == r) return void(sum[u] = s[l]);
    int mid = l + r >> 1;
    x <= mid ? update(u << 1, l, mid, x) : update(u << 1 | 1, mid + 1, r, x);
    sum[u] = sum[u << 1 | 1] * sum[u << 1];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q >> s, s = ' ' + s;
    build(1, 1, n), base[0][0] = 0;
    while (q--) {
        std::cin >> x >> ch, s[x] = ch, update(1, 1, n, x), t = sum[1] * base;
        std::cout << min(t[0][0], t[1][0], t[2][0]) << '\n';
    }
    return 0;
}