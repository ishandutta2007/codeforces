// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int l, n;
string s;

int r[19][1 << 18];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> l >> s;
    n = 1 << l;
    for (int j : ra(0, n)) {
        r[0][j] = s[j] - 'a';
    }

    for (int x : ra(0, l)) {
        int y = x + 1;
        int w = 1 << x;
        vector<array<int, 3>> ranks(n);
        for (int j : ra(0, n)) {
            int base = (j >> y) << y;
            int rot = j - base;
            int f = 0;
            if (rot >= w) {
                rot -= w;
                f = 1;
            }

            int r1 = r[x][base+rot];
            int r2 = r[x][base+w+rot];
            if (f) {
                swap(r1, r2);
            }
            ranks[j] = {r1, r2, j};
        }
        R::sort(ranks);
        r[y][ranks[0][2]] = 0;
        int u = 0;
        for (int i : ra(1, n)) {
            u += ranks[i][0] != ranks[i-1][0] || ranks[i][1] != ranks[i-1][1];
            r[y][ranks[i][2]] = u;
        }
    }

    int sol = min_element(r[l], r[l] + n) - r[l];

    string p = s;
    for (int i : ra(0, n)) {
        p[i] = s[i ^ sol];
    }

    cout << p << '\n';
}