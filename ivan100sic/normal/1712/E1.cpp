// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

vector<int> divs[400005];

void initdivs() {
    for (int x : ra(1, 400001)) {
        for (int y=x; y<=400000; y+=x) {
            divs[y].push_back(x);
        }
    }
}

struct monocounter {
    vector<int> a;
    int r;

    monocounter() : a(), r(0) {}

    void add(int x) {
        if (r == ssize(a)) r++;
        a.push_back(x);
    }

    int count_leq(int h) {
        while (r > 0 && a[r-1] > h) {
            r--;
        }
        return r;
    }

    int count_g(int h) {
        return int(a.size()) - count_leq(h);
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    initdivs();

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        ll w = (r-l+1);
        ll sol = w*(w-1)*(w-2) / 6;

        for (int k : ra(l+2, r+1)) {
            // lcm = k
            ll cnt = end(divs[k]) - R::lower_bound(divs[k], l) - 1;
            sol -= cnt * (cnt - 1) / 2;

            // lcm = 2*k
            // let 2^r || k
            int r = countr_zero((ull)k);
            // at least one of i, j must be divisible by 2^(r+1)
            int mask = (1 << (r+1)) - 1;
            monocounter g, b;
            for (int j : divs[2*k]) {
                if (j < l) continue;
                if (j >= k) break;

                int ilo = k-j;
                if ((j & mask) == 0) {
                    sol -= g.count_g(ilo) + b.count_g(ilo);
                    g.add(j);
                } else {
                    sol -= g.count_g(ilo);
                    b.add(j);
                }
            }
        }

        cout << sol << '\n';
    }
}