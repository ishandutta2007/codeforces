#include <bits/stdc++.h>
using namespace std;
int power_mod(int base, int exp, int p) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = 1LL * result * base % p;
        base = 1LL * base * base % p;
        exp >>= 1;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    auto power = bind(power_mod, placeholders::_1, placeholders::_2, p);
    vector<int> fa((n + 1) * (m + 1), -1);
    auto find = [&](int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0)
            x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    };
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j) {
            int x, y;
            if (g[i][j] == '\\') {
                x = i * (m + 1) + j;
                y = (i + 1) * (m + 1) + j + 1;
            } else if (g[i][j] == '/') {
                x = (i + 1) * (m + 1) + j;
                y = i * (m + 1) + j + 1;
            } else {
                continue;
            }
            x = find(x);
            y = find(y);
            if (x == y) {
                cout << 0 << endl;
                return 0;
            }
            fa[y] = x;
        }
    }
    auto solve = [&](int d) {
        vector<int> id((n + 1) * (m + 1), -1);
        int cnt = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                if ((i + j) % 2 == d && fa[i * (m + 1) + j] < 0)
                    id[i * (m + 1) + j] = cnt++;
        vector<vector<int>> mat(cnt);
        for (int i = 0; i < cnt; ++i)
            mat[i].resize(cnt);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == '*') {
                    int x, y;
                    if ((i + j) % 2 == d) {
                        x = i * (m + 1) + j;
                        y = (i + 1) * (m + 1) + j + 1;
                    } else {
                        x = (i + 1) * (m + 1) + j;
                        y = i * (m + 1) + j + 1;
                    }
                    x = id[find(x)];
                    y = id[find(y)];
                    ++mat[x][x];
                    ++mat[y][y];
                    --mat[x][y];
                    --mat[y][x];
                }
            }
        }
        int result = 1;
        for (int i = 0; i < cnt; ++i)
            for (int j = 0; j < cnt; ++j)
                mat[i][j] %= p;
        for (int i = 0; i < cnt - 1; ++i) {
            if (mat[i][i] == 0) {
                for (int j = i + 1; j < cnt - 1; ++j) {
                    if (mat[j][i] != 0) {
                        swap(mat[i], mat[j]);
                        result *= -1;
                        break;
                    }
                }
                if (mat[i][i] == 0)
                    return 0;
            }
            result = 1LL * result * mat[i][i] % p;
            int inv = power(mat[i][i], p - 2);
            for (int j = i; j < cnt - 1; ++j)
                mat[i][j] = 1LL * mat[i][j] * inv % p;
            for (int j = 0; j < cnt - 1; ++j) {
                if(i == j)
                    continue;
                int x = mat[j][i];
                for (int k = i; k < cnt - 1; ++k)
                    mat[j][k] = (mat[j][k] - 1LL * mat[i][k] * x) % p;
            }
        }
        return (result + p) % p;
    };
    cout << (solve(0) + solve(1)) % p << endl;
    return 0;
}