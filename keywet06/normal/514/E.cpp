#include <bits/stdc++.h>

const int N = 101;
const int p = 1000000007;

struct Matrix {
    Matrix() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) a[i][j] = 0;
        }
    }
    long long a[101][101];
    Matrix operator*(Matrix m) {
        Matrix t;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                t.a[i][j] = 0;
                for (int k = 0; k < N; ++k) t.a[i][j] = (t.a[i][j] + a[i][k] * m.a[k][j]) % p;
            }
        }
        return t;
    }
};

Matrix E;

Matrix Pow(Matrix m, int b) {
    if (b == 0) return E;
    if (b & 1) return m * Pow(m, b - 1);
    Matrix tmp = Pow(m, b / 2);
    return tmp * tmp;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    for (int i = 0; i < N; ++i) E.a[i][i] = 1;
    int n, x;
    std::cin >> n >> x;
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = 0;
    for (int t, i = 0; i < n; ++i) std::cin >> t, ++a[t - 1];
    Matrix q;
    q.a[0][0] = q.a[1][0] = 1;
    for (int i = 1; i < N; ++i) q.a[i][1] = a[i - 1];
    for (int i = 2; i < N; ++i) q.a[i - 1][i] = 1;
    q = Pow(q, x + 1), std::cout << (q.a[1][0]) % p << std::endl;
    return 0;
}