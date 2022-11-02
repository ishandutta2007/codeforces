#include <bits/stdc++.h>

using int64 = long long;

const int N = 1010;
const int P = 1e9 + 7;

int n, m;
int f[N], c[N][N];

int64 b[N];

std::map<int64, int> Map;

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1, x; j <= m; ++j) scanf("%1d", &x), b[j] += (1ll * x) << i;
    }
    for (int i = 1; i <= m; ++i) Map[b[i]]++;
    for (int i = 0; i <= m; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
    }
    f[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < i; ++j) f[i] = (f[i] + 1ll * c[i - 1][j] * f[j] % P) % P;
    }
    int ans = 1;
    for (std::map<int64, int>::iterator it = Map.begin(); it != Map.end(); ++it) ans = 1ll * ans * f[it->second] % P;
    std::cout << ans << std::endl;
    return 0;
}