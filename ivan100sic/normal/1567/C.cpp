// Retired?
#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        reverse(begin(s), end(s));
        if (n == 1) {
            cout << char(s[0]-1) << '\n';
            continue;
        }

        int sol = 0;
        for (auto mask : mask_loop(n-2)) {
            int p = 1;
            for (int i=0; i<n; i++) {
                if (mask[i]) {
                    int v = s[i] - '0';
                    if (i >= 2 && mask[i-2]) v--;
                    p *= 9 - v;
                } else {
                    int v = s[i] - '0';
                    if (i >= 2 && mask[i-2]) v--;
                    p *= v + 1;
                }
            }
            sol += p;
        }
        cout << sol-2 << '\n';
    }
}