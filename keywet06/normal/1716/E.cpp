#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353;

inline int Add(int x, int y) { return x + y >= P ? x + y - P : x + y; }
inline int Sub(int x, int y) { return x - y >= 0 ? x - y : x - y + P; }

const int N = 1 << 20;

int n, m, q, bit, a[N];

struct Node {
    int64 ans, sum, Lm, Rm;
};

std::vector<Node> f[N];

Node operator+(Node a, Node b) {
    Node Tmp;
    Tmp.ans = std::max(std::max(a.ans, b.ans), a.Rm + b.Lm), Tmp.sum = a.sum + b.sum;
    Tmp.Lm = std::max(a.Lm, a.sum + b.Lm), Tmp.Rm = std::max(b.Rm, a.Rm + b.sum);
    return Tmp;
}

void Solve(int d, int u, int l, int r) {
    f[u].resize(1 << d);
    if (l + 1 == r) {
        f[u][0].sum = a[l];
        f[u][0].ans = f[u][0].Lm = f[u][0].Rm = std::max(0, a[l]);
        return;
    }
    int mid = l + r >> 1;
    Solve(d - 1, u << 1, l, mid);
    Solve(d - 1, u << 1 | 1, mid, r);
    for (int x = 0; x < (1 << d - 1); ++x) {
        f[u][x] = f[u << 1][x] + f[u << 1 | 1][x];
        f[u][x | (1 << d - 1)] = f[u << 1 | 1][x] + f[u << 1][x];
    }
}

inline int read() {
    char Tmp, la;
    int x;
    for (Tmp = la = getchar(); !isdigit(Tmp); Tmp = getchar()) la = Tmp;
    for (x = 0; isdigit(Tmp); Tmp = getchar()) x = x * 10 + Tmp - '0';
    return la == '-' ? -x : x;
}

int main() {
    n = read(), m = 1 << n;
    for (int i = 0; i < m; ++i) a[i] = read();
    Solve(n, 1, 0, m), q = read(), bit = 0;
    for (; q; q--) {
        int d = read();
        bit ^= 1 << d;
        std::cout << f[1][bit].ans << '\n';
    }
    return 0;
}