// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int BASE = 200;

int n, q;
int p[100005], inv[100005];
int hop[100005], tbl[2*BASE + 1];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q;
    for (int i : ra(1, n+1)) {
        cin >> p[i];
        inv[p[i]] = i;
    }

    for (int i : ra(1, n+1)) {
        int t = i;
        for (int j : ra(0, BASE)) t = p[t];
        hop[i] = t;
    }
    
    auto fix = [&](int x) {
        tbl[BASE] = x;
        for (int i : ra(BASE + 1, 2*BASE + 1)) tbl[i] = p[tbl[i-1]];
        for (int i=BASE-1; i>=0; i--) tbl[i] = inv[tbl[i+1]];

        for (int i : ra(0, BASE+1)) {
            hop[tbl[i]] = tbl[i + BASE];
        }
    };

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            swap(p[x], p[y]);
            inv[p[x]] = x;
            inv[p[y]] = y;
            fix(x);
            fix(y);
        } else {
            for (int i : ra(0, y / BASE)) x = hop[x];
            for (int i : ra(0, y % BASE)) x = p[x];
            cout << x << '\n';
        }
    }

}