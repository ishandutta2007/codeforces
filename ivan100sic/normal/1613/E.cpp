// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        queue<pair<int, int>> q;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                if (a[i][j] == 'L') {
                    q.push({i, j});
                }
            }
        }

        auto ins = [&](int x, int y) {
            return clamp(x, 0, n-1) == x && clamp(y, 0, m-1) == y;
        };

        auto should = [&](int x, int y) {
            if (!ins(x, y)) return false;
            if (a[x][y] != '.') return false;
            int l = 0, d = 0;
            for (int dir : ra(0, 4)) {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (ins(xx, yy)) {
                    if (a[xx][yy] == 'L' || a[xx][yy] == '+') l++;
                    if (a[xx][yy] == '.') d++;
                }
            }

            return l >= 1 && d <= 1;
        };

        while (q.size()) {
            auto [x, y] = q.front(); q.pop();
            for (int dir : ra(0, 4)) {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (should(xx, yy)) {
                    a[xx][yy] = '+';
                    q.push({xx, yy});
                }
            }
        }

        for (auto& s : a) cout << s << '\n';
    }
        
}