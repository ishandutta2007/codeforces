// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct goood {
    ll l, r, zl, zr;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, p;
    cin >> n >> p;

    vector<int> a(n), sol;
    for (int& x : a) cin >> x;
    R::sort(R::reverse_view(a));

    vector<goood> gg(n);
    for (int i : ra(0, n)) {
        auto& g = gg[i];
        if ((n-i) % p == 0) {
            g.l = a[i] + i - n;
            g.r = g.l + n - i;
            g.zl = g.l;
            g.zr = g.r;
        } else {
            g.l = a[i] + i - n;
            g.r = 1e18;
            g.zl = g.l;
            g.zr = g.l + (n-i) / p * p;
        }
    };

    ll ul = -1e18, ur = 1e18;
    for (auto& g : gg) {
        ul = max(ul, g.l);
        ur = min(ur, g.r);
    }

    if (ul > ur) {
        cout << "0\n";
        return 0;
    }

    vector<ll> marks(ur-ul+1, 0);
    for (auto g : gg) {
        g.zl += (ul - g.zl) / p * p;
        if (g.zl < ul) g.zl += p;
        if (g.zl > g.zr) continue;
        
        if (g.zl <= ur) marks[g.zl - ul]++;
        if (g.zr+p <= ur) marks[g.zr+p - ul]--;
    }

    for (ll i=p; i<=ur-ul; i++) {
        marks[i] += marks[i-p];
    }

    for (ll i=0; i<=ur-ul; i++) {
        if (marks[i] == 0) {
            sol.push_back(i + ul);
        }
    }

    cout << sol.size() << '\n';
    for (int x : sol) cout << x << ' ';
    cout << '\n';
}