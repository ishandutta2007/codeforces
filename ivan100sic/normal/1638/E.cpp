// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int, class F = plus<T>>
struct fenwick {
    vector<T> a;
    T e;
    F f;

    fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

    void add(int p, const T& v) {
        for (p++; p <= (int)a.size(); p += p & -p)
            a[p-1] = f(a[p-1], v);
    }

    T operator() (int p) const {
        T v = e;
        p = min(p, (int)a.size());
        for (; p > 0; p -= p & -p)
            v = f(v, a[p-1]);
        return v;
    }
};

fenwick<ll> global_sum(1000005);

struct sum_entry {
    int l, r;
    ll sum;

    strong_ordering operator<=> (const sum_entry& b) const {
        return l <=> b.l;
    }
};

struct lazyaddset {
    set<sum_entry> s;
    ll lz_sum;

    void insert(int l, int r) {
        s.insert({l, r, -lz_sum});
    }

    void erase(int l) {
        auto it = s.find({l, 0, 0});
        ll w = lz_sum + it->sum;
        global_sum.add(it->l-1, w);
        global_sum.add(it->r, -w);
        s.erase(it);
    }
};

lazyaddset las[1000005];

struct seg {
    int l, r, c;
    strong_ordering operator<=> (const seg& b) const {
        return l <=> b.l;
    }
};

set<seg> doc;

void doc_replace(int l, int r, int c) {
    vector<seg> to_add = {{l, r, c}};
    auto it = --doc.upper_bound({l, 0, 0});
    while (it != doc.end() && max(l, it->l) <= min(r, it->r)) {
        las[it->c].erase(it->l);
        if (it->l < l) to_add.push_back({it->l, l-1, it->c});
        if (it->r > r) to_add.push_back({r+1, it->r, it->c});
        it = doc.erase(it);
    }

    for (auto [l, r, c] : to_add) {
        doc.insert({l, r, c});
        las[c].insert(l, r);
    }
}

int n, q;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q;
    doc.insert({1, n, 1});
    las[1].insert(1, n);
    for (int j : ra(0, q)) {
        string s;
        cin >> s;
        if (s[0] == 'A') {
            int c, x;
            cin >> c >> x;
            las[c].lz_sum += x;
        } else if (s[0] == 'Q') {
            int x;
            cin >> x;
            ll w = global_sum(x);
            auto it = --doc.upper_bound({x, 0, 0});
            int c = it->c;
            w += las[c].lz_sum;
            auto lit = --las[c].s.upper_bound({x, 0, 0});
            w += lit->sum;
            cout << w << '\n';
        } else {
            int l, r, c;
            cin >> l >> r >> c;
            doc_replace(l, r, c);
        }
    }
}