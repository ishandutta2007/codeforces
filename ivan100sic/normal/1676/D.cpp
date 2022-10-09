// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int dx[4] = {1, 1, -1, -1};
const int dy[4] = {1, -1, 1, -1};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector a(n, vector(m, 0));
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                cin >> a[i][j];
            }
        }

        int sol = 0;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                int z = a[i][j];
                for (int d : ra(0, 4)) {
                    int dx = ::dx[d];
                    int dy = ::dy[d];
                    
                    int x = i + dx;
                    int y = j + dy;
                    while (clamp(x, 0, n-1) == x && clamp(y, 0, m-1) == y) {
                        z += a[x][y];
                        x += dx;
                        y += dy;
                    }
                }
                sol = max(sol, z);
            }
        }

        cout << sol << '\n';    
    }
}