#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<vector<int64> > > g(
        5, vector<vector<int64> >(n, vector<int64>(n)));
    vector<int> deg(n);
    for (int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        --a, --b, ++g[0][a][b], ++g[0][b][a], ++deg[a], ++deg[b];
    }
    for (int len = 2; len <= 5; ++len) {
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                for (int c = a; c < n; ++c) {
                    g[len - 1][a][c] += g[len - 2][a][b] * g[0][b][c];
                }
            }
        }
        for (int a = 0; a < n; ++a) {
            for (int c = 0; c < a; ++c) g[len - 1][a][c] = g[len - 1][c][a];
        }
    }
    int64 res = 0;
    for (int a = 0; a < n; ++a) {
        res += g[4][a][a];
        if (deg[a] >= 3) res -= g[2][a][a] * (deg[a] - 2) * 5;
        if (deg[a] >= 2) res -= g[2][a][a] * 5;
    }
    cout << res / 10 << endl;
    return 0;
}