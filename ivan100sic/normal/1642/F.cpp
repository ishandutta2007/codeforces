// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct bitmask {
    int m;

    bitmask(int m = 0) : m(m) {}
    operator int() const { return m; }
    int operator() () const { return m; }
    bitmask operator& (bitmask b) const { return m & b.m; }
    bitmask operator| (bitmask b) const { return m | b.m; }
    bitmask operator^ (bitmask b) const { return m ^ b.m; }
    bitmask& operator&= (bitmask b) { return *this = *this & b; }
    bitmask& operator|= (bitmask b) { return *this = *this | b; }
    bitmask& operator^= (bitmask b) { return *this = *this ^ b; }
    bitmask& set(int i) { m |= 1 << i; return *this; }
    bitmask& reset(int i) { m &= ~(1 << i); return *this; }
    bitmask& flip(int i) { m ^= 1 << i; return *this; }
    int operator[](int i) const { return 1 & (m >> i); }
    int popcnt() { return __builtin_popcount(m); }

    struct iterator {
        int n, i, m, v;
        void mv() { while (i < n && v != ((m >> i) & 1)) i++; }
        int operator*() const { return i; }
        bool operator== (const iterator& b) const { return i == b.i; }
        bool operator!= (const iterator& b) const { return !(*this == b); }
        iterator& operator++() { i++; mv(); return *this; }
    };

    struct iterable {
        int n, m, v;
        iterator begin() const { iterator i{n, 0, m, v}; i.mv(); return i; }
        iterator end() const { iterator i{n, n, m, v}; i.mv(); return i; }
    };

    iterable on(int n) const { return {n, m, 1}; }
    iterable off(int n) const { return {n, m, 0}; }
};

struct mask_loop {
    int f, t;

    // size of mask, number of items to skip from start and end
    mask_loop(int n, int f = 0, int t = 0) : f(f), t((1 << n) - t) {
        t = max(t, f);
    }

    struct iterator {
        int m;
        bitmask operator*() const { return m; }
        bool operator== (const iterator& b) const { return m == b.m; }
        bool operator!= (const iterator& b) const { return !(*this == b); }
        iterator& operator++() { m++; return *this; }
    };

    iterator begin() const { return {f}; }
    iterator end() const { return {t}; }
};

const ull base = 543789187247871;
int n, m;
int w[100005];
using elem = pair<ull, int>;
vector<elem> gs1;

ull solve_group(auto g, int h) {
    int n = size(g), j = n;
    ull z = 0;
    for (int i=0; i<n; i++) {
        while (j > 0 && g[j-1] + g[i] > h) {
            j--;
        }

        z += j;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i : ra(0, n)) {
        int a[5];
        for (int j : ra(0, m)) {
            cin >> a[j];
        }
        sort(a, a+m);
        int w;
        cin >> w;

        for (auto mask : mask_loop(m)) {
            ull h = 0;
            for (int i : mask.on(m)) {
                h = h * base + a[i] * 2ull + 1;
            }
            gs1.emplace_back(h, w);
        }
    }

    R::sort(gs1);
    elem* b = gs1.data();
    vector<span<elem>> groups;
    for (int i = 1; i < ssize(gs1); i++) {
        if (gs1[i].first != gs1[i-1].first) {
            groups.push_back({b, &gs1[i]});
            b = &gs1[i];
        }
    }
    groups.push_back({b, gs1.data() + gs1.size()});

    auto check = [&](int m) {
        ull z = 0;
        for (auto group : groups) {
            ull t = solve_group(group | R::views::transform(&elem::second), m);
            if (group[0].first & 1) z += t;
            else z -= t;
        }

        return z != 0;
    };

    const int inf = 2'000'000'009;
    int sol = *R::lower_bound(ra(0, inf), true, {}, check);
    if (sol == inf) {
        sol = -1;
    }
    cout << sol << '\n';
}