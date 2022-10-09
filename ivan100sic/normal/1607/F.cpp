// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;

pair<int, int> mv(int x, int y, char c) {
    switch (c) {
        case 'L': return {x, y-1};
        case 'R': return {x, y+1};
        case 'U': return {x-1, y};
        case 'D': return {x+1, y};
    }
    return {-1, -1};
}

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        vector d(n, vector(m, -1));
        vector cyc(n, vector(m, false));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (d[i][j] != -1) continue;

                int x = i, y = j, cx = -1, cy = -1, ref = -1;
                d[x][y] = -2;
                vector<pair<int, int>> path;
                while (1) {
                    path.emplace_back(x, y);
                    tie(x, y) = mv(x, y, a[x][y]);
                    if (!ok(x, y)) {
                        ref = 0;
                        break;
                    }

                    if (d[x][y] == -2) {
                        cx = x;
                        cy = y;
                        break;
                    } else if (d[x][y] != -1) {
                        ref = d[x][y];
                        break;
                    } else {
                        d[x][y] = -2;
                    }
                }

                if (ref != -1) {
                    for (int i : ra(0, ssize(path))) {
                        auto [x, y] = path[i];
                        d[x][y] = ssize(path) - i + ref;
                    }
                } else {
                    auto it = R::find(path, pair{cx, cy}) - path.begin();
                    for (int i : ra(it, ssize(path))) {
                        auto [x, y] = path[i];
                        d[x][y] = ssize(path) - it;
                    }

                    for (int i : ra(0, it)) {
                        auto [x, y] = path[i];
                        d[x][y] = ssize(path) - i;
                    }
                }
            }
        }

        int best = 0, ii = 0, jj = 0;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                if (d[i][j] > best) {
                    best = d[i][j];
                    ii = i;
                    jj = j;
                }
            }
        }

        cout << ii+1 << ' ' << jj+1 << ' ' << best << '\n';
    }
}