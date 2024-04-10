#include <bits/stdc++.h>

using int64 = long long;

const int N = 405;
const int P = 1000000007;

int f[N][N], C[N][N];

int Dfs(int i, int j) {
    if (f[i][j]) return f[i][j] - 1;
    int s = 0;
    if (!j) {
        s = 1;
    } else if (i == 1) {
        s = (j == 1);
    } else {
        for (int x = 0; x <= j; ++x) s = (s + C[j][x] * (int64)Dfs(i - 1, x) % P * Dfs(i - 1, j - x)) % P;
        for (int x = 0; x < j; ++x) {
            int t = 0;
            t = (t + Dfs(i - 1, x) * (int64)Dfs(i - 1, j - x - 1)) % P;
            t = (t + Dfs(i - 1, x + 1) * (int64)Dfs(i - 1, j - x - 1) * 2) % P;
            t = (t + Dfs(i - 1, x) * (int64)Dfs(i - 1, j - x) * 2) % P;
            t = (t + Dfs(i - 1, x + 2) * (int64)Dfs(i - 1, j - x - 1)) % P;
            t = (t + Dfs(i - 1, x) * (int64)Dfs(i - 1, j - x + 1)) % P;
            t = (t + Dfs(i - 1, x + 1) * (int64)Dfs(i - 1, j - x) * 2) % P;
            s = (s + j * (int64)C[j - 1][x] % P * t) % P;
        }
    }
    f[i][j] = s;
    return f[i][j]++;
}

int main() {
    int k;
    std::cin >> k;
    for (int i = 0; i <= k; ++i) {
        for (int j = *C[i] = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    std::cout << Dfs(k, 1) << '\n';
    return 0;
}