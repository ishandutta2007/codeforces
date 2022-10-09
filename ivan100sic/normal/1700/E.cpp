// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {1, 0, -1, 0, 0};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m;
    cin >> n >> m;
    vector a(n, vector(m, 0));
    vector mul(n, vector(m, 0));

    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;

    auto valid = [&](int i, int j) {
        for (int d : ra(0, 4)) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x >= 0 && y >= 0 && x < n && y < m && a[x][y] < a[i][j]) {
                return 1;
            }
        }
        return 0;
    };

    auto add = [&](int i, int j, int tgt) {
        if (i >= 0 && j >= 0 && i < n && j < m) {
            int v = valid(i, j);
            cnt -= mul[i][j] * v;
            mul[i][j] = tgt;
            cnt += mul[i][j] * v;
        }
    };

    auto add5 = [&](int i, int j, int tgt) {
        for (int d : ra(0, 5)) {
            add(i + dx[d], j + dy[d], tgt);
        }
    };

    int bad_i = -1, bad_j = -1;

    for (int i : ra(0, n)) {
        for (int j : ra(0, m)) {
            mul[i][j] = 1;
            if (valid(i, j)) {
                cnt++;
            } else if (a[i][j] > 1) {
                bad_i = i;
                bad_j = j;
            }
        }
    }

    if (cnt == n*m-1) {
        cout << "0\n";
        return 0;
    }

    vector<ll> h;

    for (int d : ra(0, 5)) {
        int x1 = bad_i + dx[d];
        int y1 = bad_j + dy[d];

        if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) {
            continue;
        }

        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                if (i == x1 && j == y1) {
                    continue;
                }

                add5(x1, y1, 0);
                add5(i, j, 0);
                swap(a[i][j], a[x1][y1]);
                add5(x1, y1, 1);
                add5(i, j, 1);

                if (cnt == n*m-1) {
                    ll p = i, q = j, r = x1, s = y1;
                    if (tie(p, q) > tie(r, s)) {
                        swap(p, r);
                        swap(q, s);
                    }
                    h.push_back(p + 1ll*n*q + 1ll*n*m*r + 1ll*n*m*n*s);
                }

                add5(x1, y1, 0);
                add5(i, j, 0);
                swap(a[i][j], a[x1][y1]);
                add5(x1, y1, 1);
                add5(i, j, 1);
            }
        }
    }

    if (h.size()) {
        sort(h.begin(), h.end());
        h.erase(unique(h.begin(), h.end()), h.end());
        cout << "1 " << h.size() << '\n';
    } else {
        cout << "2\n";
    }
}