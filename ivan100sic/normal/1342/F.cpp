// Retired?
#ifndef LOCAL
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

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

struct submask_loop {
    int m;

    submask_loop(int m) : m(m) {}

    struct iterator {
        int i, m;
        bitmask operator*() const { return m - i; }
        bool operator== (const iterator& b) const { return i == b.i; }
        bool operator!= (const iterator& b) const { return !(*this == b); }
        iterator& operator++() { i = i ? (i-1) & m : -1; return *this; }
    };

    iterator begin() const { return {m, m}; }
    iterator end() const { return {-1, m}; }
};

struct info;

struct info_ptr {
    int h = -1;

    info* operator->() const;
    info& operator*() const;
};

struct info {
    uint16_t mask;
    uint8_t hook;
    int8_t val;
    info_ptr prev;

    info(int m=0, int h=0, int v=-100, info_ptr p={}) : mask(m), hook(h), val(v), prev(p) {}
};

namespace info_arena {
    const int MaxSize = 25'000'000;
    info a[MaxSize];
    int sz = 0;

    info_ptr alloc() {
        if (sz == MaxSize) exit(1);
        return { sz++ };
    }

    void reset() {
        fill(a, a+sz, info{});
        sz = 0;
    }
}

info* info_ptr::operator->() const {
    return info_arena::a + h;
}

info& info_ptr::operator*() const {
    return info_arena::a[h];
}

int n;
int a[15];
info_ptr d[1<<15][16];

int main() {
    ios::sync_with_stdio(!cin.tie(0));


    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        // clear
        info_arena::reset();
        info_ptr bad = info_arena::alloc();
        info_ptr zero = info_arena::alloc();
        *zero = {0, 0, 0};

        for (int i : ra(0, 1<<n)) {
            for (int j : ra(0, n+1)) {
                d[i][j] = bad;
            }
        }
        d[0][0] = zero;

        const int n_ones = (1<<n) - 1;
        for (int i : ra(0, n)) {
            cin >> a[i];
        }

        vector<pair<int, int>> b;
        for (auto m : mask_loop(n, 1)) {
            int z = 0;
            for (int i : m.on(n)) {
                z += a[i];
            }
            b.emplace_back(z, m());
        }

        R::sort(b);
        for (int i=0; i<ssize(b);) {
            int j = i;
            while (j < ssize(b) && b[j].first == b[i].first) j++;

            // compute changes
            vector<pair<info_ptr*, info>> changes;
            for (int id : ra(i, j)) {
                const int adding = b[id].second;
                const int max_hook = bit_width((unsigned)adding) - 1;
                for (auto sm : submask_loop(n_ones ^ adding)) {
                    for (int h=0; h<=max_hook; h++) {
                        int val = d[sm][h]->val + 1;
                        if (val < 0) continue;
                        
                        int nm = sm() | adding;
                        int h2 = countr_zero(unsigned(adding >> h)) + h + 1;
                        if (d[nm][h2]->val < val) {
                            changes.emplace_back(&d[nm][h2], info{nm, h2, val, d[sm][h]});
                        }
                    }
                }
            }

            // apply changes
            for (auto [loc, val] : changes) {
                if (val.val > (*loc)->val) {
                    auto nu = info_arena::alloc();
                    *nu = val;
                    *loc = nu;
                }
            }

            // move on
            i = j;
        }

        info_ptr base = bad;
        for (int i : ra(0, n+1)) {
            auto c = d[n_ones][i];
            if (c->val > base->val) {
                base = c;
            }
        }

        cout << n - base->val << '\n';

        // sparse moves
        vector<int> a(n, 1);

        auto acnt = [&](int i) {
            return R::count(span(a).subspan(0, i+1), 1);
        };

        auto do_move = [&](int i, int j) {
            cout << acnt(i) << ' ' << acnt(j) << '\n';
            a[i] = 0;
        };

        // backtrace
        for (info_ptr i = base; i->mask;) {
            info_ptr nxt = i->prev;
            int tgt = i->hook - 1;
            for (int j : bitmask(i->mask - nxt->mask).on(n)) {
                if (j != tgt) {
                    do_move(j, tgt);
                }
            }
            i = nxt;
        }
    }
}