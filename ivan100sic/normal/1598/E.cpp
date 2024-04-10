// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m, q, sol;
char a[1005][1005];

int kod(int x0, int y0) {
    int r[2][2];
    memset(r, 0, sizeof(r));
    for (int dir : {-1, 1}) {
        for (int dx : {0, dir}) {
            int& cnt = r[(dir+1)/2][abs(dx)];
            cnt = 1;
            int dy = dir - dx;
            int x = x0;
            int y = y0;

            while (1) {
                x += dx;
                y += dy;
                if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == 1) {
                    break;
                }
                cnt++;
                swap(dx, dy);
            }
        }
    }

    return r[0][1] * r[1][0] + r[0][0] * r[1][1] - 1;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> q;
    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            if (i == j) sol += 4*i + 1;
            else sol += 4*min(i, j) + 2;
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int t = kod(x, y);
        if (a[x][y]) {
            sol += t;
        } else {
            sol -= t;
        }
        a[x][y] ^= 1;
        cout << sol << '\n';
    }
}