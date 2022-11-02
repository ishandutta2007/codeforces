#include <bits/stdc++.h>

const int N = 405;
const int D = 3;

int T, n, m, ans, u, x, o, v;
int p[D], t[D];
int a[N][N], pre[N][N];

std::string s[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) std::cin >> s[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) pre[i][j] = a[i][j] = s[i][j] == '1';
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) pre[i][j] += pre[i - 1][j];
        }
        ans = 1e9;
        for (int l = 0; l < n; ++l) {
            for (int r = l + 4; r < n; ++r) {
                memset(p, 1, sizeof(p)), u = o = 0;
                for (int i = 0; i < m; ++i) {
                    v = p[o];
                    if (++o == D) o = 0;
                    x = r - l - 1 - pre[r - 1][i] + pre[l][i];
                    ans = std::min(ans, u + p[o] + x);
                    u += !a[l][i] + !a[r][i] + pre[r - 1][i] - pre[l][i];
                    p[o] = std::min(std::min(v, p[o]), x - u);
                }
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}