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

    cached_interactive<pair<ll, ll>, ll> ci;

    vector<ll> sol;

    for (int x : ra(2, 27)) {
        ll d1 = ci.ask(1, x);
        ll d2 = ci.ask(x, 1);

        if (d1 <= 0 || d2 <= 0) {
            ci.answer(x-1);
            return 0;
        } else if (d1 != d2) {
            ci.answer(d1 + d2);
        }
    }
}