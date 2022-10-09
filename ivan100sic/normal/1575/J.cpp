// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m, k;
int a[1005][1005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> k;

    for (int i : ra(1, n+1)) {
        for (int j : ra(1, m+1)) {
            cin >> a[i][j];
        }
    }

    for (int i : ra(0, k)) {
        int y;
        cin >> y;
        int x = 1;
        while (x <= n) {
            if (a[x][y] == 1) {
                a[x][y] = 2;
                y++;
            } else if (a[x][y] == 3) {
                a[x][y] = 2;
                y--;
            } else {
                x++;
            }
        }

        cout << y << ' ';
    }
    cout << '\n';
}