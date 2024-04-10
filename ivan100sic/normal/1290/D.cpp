// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;
using vi = vector<int>;

ll n, k;

bool ask(int x) {
    cout << "? " << x << '\n' << flush;
    char c;
    cin >> c;
    return c == 'Y';
}

void reset() {
    cout << "R\n" << flush;
}

void answer(int d) {
    cout << "! " << d << '\n' << flush;
    exit(0);
}

vi subvec(vi sp, ll from, ll sz = -1) {
    if (sz == -1) sz = ssize(sp) - from;
    return vi(begin(sp) + from, begin(sp) + from + sz);
}

vi vcat(vi a, vi b) {
    a.insert(a.end(), begin(b), end(b));
    return a;
}

pair<vi, vi> axa(vi a, vi b) {
    if (a.empty() || b.empty()) return {a, b};
    ll an = ssize(a);
    ll bn = ssize(b);
    vi as(an), bs(bn);
    // a part
    for (int i : a) ask(i);
    // b part
    for (int j : ra(0, bn)) {
        if (ask(b[j])) {
            bs[j] = 1;
        }
    }

    // b filler
    for (int _i : ra(0, 2*k+1 - an - bn)) {
        ask(b.back());
    }

    // a repeat
    auto arep = an - (k + 1 - bn);
    for (int j=0; j<arep; j++) {
        if (ask(a[j])) {
            as[j] = 1;
        }
    }

    reset();
    vi ar, br;
    for (int i : ra(0, an)) if (!as[i]) ar.push_back(a[i]);
    for (int i : ra(0, bn)) if (!bs[i]) br.push_back(b[i]);
    return {ar, br};
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;

    // initial groups
    vector<vector<int>> gg;
    for (int i=1; i<=n; i+=k) {
        vector<int> g;
        for (int j=i; j<i+k; j++) {
            if (!ask(j)) {
                g.push_back(j);
            }
        }
        gg.push_back(g);
        reset();
    }

    for (int i : ra(0, ssize(gg))) {
        for (int j : ra(0, i)) {
            tie(gg[i], gg[j]) = axa(gg[i], gg[j]);
        }
    }

    int sz = 0;
    for (auto& g : gg) sz += ssize(g);
    answer(sz);
}