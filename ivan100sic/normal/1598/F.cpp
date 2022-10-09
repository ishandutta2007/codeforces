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

void vadd(vector<vector<int>>& a, int p, int v) {
    while (p >= ssize(a)) a.emplace_back(0);
    a[p].push_back(v);
}

int vget(const vector<vector<int>>& a, int p, int h) {
    if (p >= ssize(a)) return 0;
    return R::lower_bound(a[p], h) - a[p].begin();
}

struct zag {
    int sum, maxdrop;
    vector<vector<int>> a;
} a[20];

int n;
int d[1 << 20], globalsol;

void mx(int& x, int y) {
    x = max(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) {
        auto& z = a[i];
        string s;
        cin >> s;
        for (int i : ra(0, ssize(s))) {
            int x = s[i] == '(' ? 1 : -1;
            z.sum += x;
            z.maxdrop = min(z.maxdrop, z.sum);
            if (z.sum <= 0) {
                vadd(z.a, -z.sum, i+1);
            }
        }
    }

    memset(d, 192, sizeof(d));
    d[0] = 0;
    for (auto m : mask_loop(n)) {
        int sum = 0;
        if (d[m] < 0 || sum < 0) continue;
        for (int j : m.on(n)) sum += a[j].sum;
        
        for (int j : m.off(n)) {
            auto& z = a[j];

            if (z.maxdrop + sum >= 0) {
                // stays alive
                mx(d[m() | (1 << j)], d[m] + vget(z.a, sum, 123123123));
            } else {
                // dies
                int pd = z.a[sum+1][0];
                mx(globalsol, d[m] + vget(z.a, sum, pd));
            }
        }
    }

    mx(globalsol, *max_element(d, d+(1<<n)));
    cout << globalsol << '\n';
}