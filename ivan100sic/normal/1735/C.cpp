// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const auto L = ra(0, 26);

bool good(span<const int> q) {
    // f is <= 1
    array<int, 26> f;
    R::fill(f, 0);

    for (int x : q) {
        if (x >= 0) {
            f[x]++;
        }
    }

    if (R::max(f) >= 2) return false;

    // no cycles < 26
    array<bool, 26> vis;
    R::fill(vis, 0);

    for (int x : L) {
        if (!vis[x]) {
            int y = x, c = 0;
            while (y != -1 && !vis[y]) {
                vis[y] = 1;
                c++;
                y = q[y];
            }

            if (y == x && c != 26) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, sol;
        cin >> n >> s;

        array<int, 26> p;
        R::fill(p, -1);

        for (char c : s) {
            int x = c - 'a';

            if (p[x] == -1) {
                for (int y : L) {
                    auto q = p;
                    q[x] = y;

                    // check for consistency
                    if (good(q)) {
                        p[x] = y;
                        break;
                    }
                }
            }

            sol += char(p[x] + 'a');
        }
        
        cout << sol << "\n";
    }
}