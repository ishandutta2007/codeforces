#include <bits/stdc++.h>

typedef long long int64;

const int64 P = (int64)1e9 + 7;

int64 Add(int64 x, int64 y) {
    x += y;
    if (x >= P) return x - P;
    return x;
}

int64 Sub(int64 x, int64 y) {
    x -= y;
    if (x < 0) return x + P;
    return x;
}

int64 Mul(int64 x, int64 y) { return (x * y) % P; }

int64 Pow(int64 x, int64 p) {
    if (p == 0) return 1;
    if (p & 1) return Mul(x, Pow(x, p - 1));
    return Pow(Mul(x, x), p / 2);
}

int64 Rev(int64 x) { return Pow(x, P - 2); }

const int N = 200200;

int64 f[N], rf[N];

int64 getC(int n, int k) {
    if (k < 0 || k > n) return 0;
    return Mul(f[n], Mul(rf[k], rf[n - k]));
}

int64 A = 0, B = 0;

int64 getS(int n, int k) {
    if (k > n) return 0;
    int64 res = 0;
    for (int x = k; x > 0; --x) {
        int64 val = Mul(getC(k, x), Pow(x, n));
        res = (k - x) & 1 ? Sub(res, val) : Add(res, val);
    }
    return Mul(rf[k], res);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = Mul(f[i - 1], i);
    rf[N - 1] = Rev(f[N - 1]);
    for (int i = N - 1; i > 0; --i) rf[i - 1] = Mul(rf[i], i);
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int64 x;
        std::cin >> x;
        A = Add(A, x);
    }
    B = Add(getS(n, k), Mul(n - 1, getS(n - 1, k)));
    std::cout << Mul(A, B) << '\n';
    return 0;
}