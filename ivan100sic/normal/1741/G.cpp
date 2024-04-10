// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class X, class Y>
struct indexed_vector : vector<Y> {
    indexed_vector(size_t n = 0, Y val = {}) : vector<Y>(n, val) {}

    Y& operator[] (X x) { return this->at((int)x); }
    Y& operator[] (X x) const { return this->at((int)x); }
};

enum class vertex : int;
enum class friend_id : int;
enum class loser_id : int;

using distances = indexed_vector<vertex, int>;

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

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        indexed_vector<vertex, vector<vertex>> e(n);
        for (int i : ra(0, m)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            vertex u{x}, v{y};
            e[u].push_back(v);
            e[v].push_back(u);
        }

        // s.p.
        auto sp = [&](vertex z) {
            queue<vertex> q;
            q.push(z);
            distances d(n, -1);
            d[z] = 0;
            while (q.size()) {
                vertex x = q.front(); q.pop();
                for (vertex y : e[x]) {
                    if (d[y] == -1) {
                        d[y] = d[x] + 1;
                        q.push(y);
                    }
                }
            }
            return d;
        };

        auto d0 = sp(vertex{0});

        int f;
        cin >> f;
        auto friends = R::transform_view(ra(0, f), [](int x) { return friend_id{x}; });

        indexed_vector<friend_id, vertex> h(f);
        for (auto i : friends) {
            int x;
            cin >> x;
            x--;
            h[i] = vertex{x};
        }

        int k;
        cin >> k;
        auto losers = R::transform_view(ra(0, k), [](int x) { return loser_id{x}; });

        indexed_vector<loser_id, friend_id> ls(f);
        indexed_vector<friend_id, char> is_loser(f, 0);

        for (auto i : losers) {
            int x;
            cin >> x;
            x--;
            ls[i] = friend_id{x};
            is_loser[ls[i]] = 1;
        }

        indexed_vector<loser_id, distances> dwc(k);
        for (auto i : losers) {
            dwc[i] = sp(h[ls[i]]);
        }

        indexed_vector<friend_id, vector<int>> masks(f);
        {
            vector<loser_id> p(k);
            R::copy(losers, begin(p));

            do {
                for (int l : ra(1, k+1)) {
                    bool ok = 1;
                    int mask = 0;
                    for (int i : ra(0, l)) {
                        mask |= 1 << (int)p[i];
                    }

                    for (int i : ra(1, l)) {
                        vertex x = h[ls[p[i-1]]];
                        vertex y = h[ls[p[i]]];

                        if (d0[y] != d0[x] + dwc[p[i-1]][y]) {
                            ok = 0;
                            break;
                        }
                    }

                    if (ok) {
                        vertex x = h[ls[p[l-1]]];
                        for (auto i : friends) {
                            if (!is_loser[i]) {
                                vertex y = h[i];
                                if (d0[y] == d0[x] + dwc[p[l-1]][y]) {
                                    masks[i].push_back(mask);
                                }
                            }
                        }
                    }
                }

            } while (R::next_permutation(p).found);
        }

        string dp(1 << k, 0);
        dp[0] = 1;

        for (auto i : friends) {
            auto nu = dp;
            for (int j : masks[i]) {
                for (int x : submask_loop((1 << k) - 1 - j)) {
                    nu[x | j] |= dp[x];
                }
            }
            swap(nu, dp);
        }

        int sol = 0;
        for (int x : ra(0, 1 << k)) {
            if (dp[x]) {
                sol = max(sol, (int)popcount((unsigned)x));
            }
        }

        cout << k-sol << '\n';
    }    
}