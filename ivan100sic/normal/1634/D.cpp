// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class I, class O = int>
struct cached_interactive {
    map<I, O> c;

    template<class... T>
    O ask(T... a) {
        I i{a...};
        auto it = c.lower_bound(i);
        if (it == c.end() || i < it->first) {
            cout << '?';
            ((cout << ' ' << a), ...) << endl;
            O o;
            cin >> o;
            c.emplace_hint(it, i, o);
            return o;
        } else {
            return it->second;
        }
    }

    template<class... T>
    void answer(T... a) {
        cout << '!';
        ((cout << ' ' << a), ...) << endl;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cached_interactive<multiset<int>> io;

        int x=1, y=2;

        auto step = [&](int i, int j) {
            int h = max({
                io.ask(x, y, i),
                io.ask(x, y, j),
                io.ask(x, i, j),
                io.ask(y, i, j)
            });

            int a[4] = {x, y, i, j}, xx=0, yy=0;
            for (int x : a) {
                for (int y : a) {
                    if (x != y) {
                        int ok = 0;
                        for (int z : a) {
                            if (z == x || z == y) continue;
                            ok += h == io.ask(x, y, z);
                        }
                        if (ok == 2) {
                            xx = x, yy = y;
                        }
                    }
                }
            }
            x = xx, y = yy;
        };

        for (int i=3; i+1<=n; i+=2) {
            step(i, i+1);
        }

        if (n % 2 == 1) {
            int c = 1;
            while (c == x || c == y) c++;
            step(c, n);
        }

        io.answer(x, y);
    }
}