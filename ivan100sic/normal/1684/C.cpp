// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector a(n, vector(m, 0));
        for (auto& x : a) {
            for (int& y : x) {
                cin >> y;
            }
        }

        // find weights
        int w = 0;
        int bad = -1;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m-1)) {
                if (a[i][j] > a[i][j+1]) {
                    w++;
                    bad = j;
                }
            }
        }

        if (bad == -1) {
            cout << "1 1\n";
            continue;
        }

        // try swapping bad and bad-1 with all
        int solx=-1, soly=-1;

        auto check = [&](int u, int v) {
            auto addw = [&](int j, int d) {
                if (j < 0 || j >= m-1) return;

                for (int i : ra(0, n)) {
                    if (a[i][j] > a[i][j+1]) {
                        w += d;
                    }
                }
            };

            auto prep = [&]() {
                for (int j : set<int>{u-2, u-1, u, u+1, u+2, v-2, v-1, v, v+1, v+2}) {
                    addw(j, -1);
                }

                for (int i : ra(0, n)) {
                    swap(a[i][u], a[i][v]);
                }

                for (int j : set<int>{u-2, u-1, u, u+1, u+2, v-2, v-1, v, v+1, v+2}) {
                    addw(j, 1);
                }
            };

            prep();
            if (w == 0) {
                solx = u;
                soly = v;
            }
            prep();
        };

        for (int j : ra(0, m)) {
            if (bad+1 < m) {
                check(j, bad+1);
            }
            check(j, bad);
        }

        if (solx == -1) {
            cout << "-1\n";
        } else {
            cout << solx+1 << ' ' << soly+1 << '\n';
        }
    }
    
}