#include <bits/stdc++.h>

const int C = 6;
const int D = 3;
const int N = 200005;

const int ex[C][D] = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

int n, q, ans, l, r;
int sum[C][N];

std::string s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q;
    std::cin >> s, s = ' ' + s;
    for (int i = 1; i <= n; ++i) {
        s[i] -= 'a';
        for (int c = 0; c < C; ++c) {
            sum[c][i] = sum[c][i - 1] + (s[i] != ex[c][i % D]);
        }
    }
    while (q--) {
        std::cin >> l >> r;
        ans = n;
        for (int c = 0; c < C; ++c) {
            ans = std::min(ans, sum[c][r] - sum[c][l - 1]);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}