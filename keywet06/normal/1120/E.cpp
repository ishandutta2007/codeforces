#include <bits/stdc++.h>

using ldou = long double;

const int N = 1007;
const int C = 3007;

int can[N][2 * C];

std::pair<int, int> q[2 * N * C + 1234];

std::array<int, 3> Fr[N][2 * C];

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    int ql = 0, qr = 1;
    q[0] = std::make_pair(0, C);
    while (ql < qr) {
        int carry = q[ql].first, Bal = q[ql].second, ldou = 0;
        ++ql;
        if (carry == 0 && Bal == C) ldou = 1;
        for (int d = ldou; d < 10; ++d) {
            int Nca = (carry + n * d) / 10;
            int NDi = (carry + n * d) % 10;
            int Nba = Bal + NDi * n - d;
            if (Nba >= 0 && Nba < 2 * C) {
                if (!can[Nca][Nba]) {
                    can[Nca][Nba] = 1;
                    Fr[Nca][Nba][0] = carry;
                    Fr[Nca][Nba][1] = Bal;
                    Fr[Nca][Nba][2] = d;
                    q[qr++] = std::make_pair(Nca, Nba);
                }
            }
        }
    }
    if (!can[0][C]) {
        std::cout << -1 << "\n";
        return 0;
    }
    std::string ans;
    int x = 0, y = C;
    do {
        int nx = Fr[x][y][0];
        int ny = Fr[x][y][1];
        ans += char('0' + Fr[x][y][2]);
        x = nx, y = ny;
    } while (x != 0 || y != C);
    while (ans[0] == '0') ans.erase(ans.begin());
    std::cout << ans << "\n";
    return 0;
}