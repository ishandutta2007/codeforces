#include <bits/stdc++.h>

const int P = 998244353;

int n, m, i, j, k, l;
int f[200005][1 << 3][1 << 3];

std::string st;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> st;
    n = st.size();
    std::reverse(st.begin(), st.end());
    f[n][7][7] = 1;
    for (i = n; i >= 1; --i) {
        for (j = 0; j < 8; ++j) {
            for (k = 0; k < 8; ++k) {
                if (!f[i][j][k]) continue;
                int lim = (st[i - 1] == '0' ? (7 ^ j) : 7);
                for (l = 0; l < 8; ++l)
                    if ((l & lim) == l) {
                        int x = (l & 1), y = ((l >> 1) & 1), z = ((l >> 2) & 1);
                        int a = x ^ y, b = x ^ z, c = y ^ z, nk = k;
                        if (a | b | c) {
                            if (!a) nk &= 6;
                            if (!b) nk &= 5;
                            if (!c) nk &= 3;
                        }
                        int nj = j;
                        if (st[i - 1] == '1') nj &= l;
                        f[i - 1][nj][nk] += f[i][j][k];
                        if (f[i - 1][nj][nk] >= P) f[i - 1][nj][nk] -= P;
                    }
            }
        }
    }
    int ans = 0;
    for (i = 0; i < 8; ++i) ans = (ans + f[0][i][0]) % P;
    std::cout << ans << std::endl;
    return 0;
}