// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> e(m);
        for (int i : ra(0, m)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[i] = {x, y, i};
        }

        string sol(m, '0');
        while (1) {
            union_find u[2] = {{n}, {n}};
            R::shuffle(e, eng);
            bool ok = 1;
            for (auto [x, y, id] : e) {
                int f = eng() & 1;
                if (!u[f].join(x, y)) {
                    if (!u[1-f].join(x, y)) {
                        ok = 0;
                        break;
                    } else {
                        f ^= 1;
                    }
                }
                sol[id] = f + '0';
            }
            if (ok) {
                break;
            }
        }

        cout << sol << '\n';
    }
}