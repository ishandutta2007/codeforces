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

int n;
int a[1005];

void two_same() {
    sort(a, a+n);
    int k = unique(a, a+n) - a;
    if (k < n) {
        cout << "YES\n";
        for (int i=0; i<n; i++) {
            cout << (i < k ? a[i] : 0) << " \n"[i == n-1];
        }
        exit(0);
    }
}

void no() {
    cout << "NO\n";
    exit(0);
}

void print_except(set<int> s, int delta) {
    for (int i=0; i<n; i++) {
        if (!s.count(a[i])) {
            cout << a[i] + delta << ' ';
        }
    }
}

void even_odd() {
    vector<int> e[2];
    for (int i=0; i<n; i++) {
        e[a[i] % 2].push_back(a[i]);
    }

    if (e[0].size() == 1 || e[0].size() == 2) {
        if (e[1].size() <= 1) {
            no();
        }

        int x = e[0][0], y = e[1][0], z = e[1][1];
        cout << "YES\n";
        cout << (x+y-z)/2 << ' ' << (x+z-y)/2 << ' ' << (z+y-x)/2 << ' ';
        print_except({x, y, z}, -(x+y-z)/2);
        cout << '\n';
        exit(0);
    }

    if (e[0].size() >= 3) {
        int x = e[0][0], y = e[0][1], z = e[0][2];
        cout << "YES\n";
        cout << (x+y-z)/2 << ' ' << (x+z-y)/2 << ' ' << (z+y-x)/2 << ' ';
        print_except({x, y, z}, -(x+y-z)/2);
        cout << '\n';
        exit(0);
    }
}

void all_odd() {
    int m = min(n, 26);
    int h = m / 2;

    map<pair<int, int>, pair<int, int>> mp;
    
    for (auto pl : mask_loop(h)) {
        for (auto mn : submask_loop((1 << h) - 1 - pl)) {
            int z = 0, c = 0;
            for (int i : pl.on(h)) {
                z += a[i];
                c += 1;
            }

            for (int i : mn.on(h)) {
                z -= a[i];
                c -= 1;
            }

            mp[{z, c}] = {pl(), mn()};
        }
    }

    int h2 = m - h;
    for (auto pl : mask_loop(h2)) {
        for (auto mn : submask_loop((1 << h2) - 1 - pl)) {
            int z = 0, c = 0;
            for (int i : pl.on(h2)) {
                z += a[i+h];
                c += 1;
            }

            for (int i : mn.on(h2)) {
                z -= a[i+h];
                c -= 1;
            }

            auto it = mp.find({-z, -c});
            if (it != mp.end()) {
                auto [plx, mnx] = it->second;

                if ((plx | mnx | pl | mn) == 0) {
                    continue;
                }

                vector<int> plid, mnid;
                for (int i : bitmask(pl).on(h2)) plid.push_back(i+h);
                for (int i : bitmask(plx).on(h)) plid.push_back(i);
                for (int i : bitmask(mn).on(h2)) mnid.push_back(i+h);
                for (int i : bitmask(mnx).on(h)) mnid.push_back(i);

                vector<int> ring;

                ring.push_back(0);
                set<int> excl;
                for (int i=0; i<(int)plid.size(); i++) {
                    int x = a[plid[i]], y = a[mnid[i]];
                    excl.insert(x);
                    excl.insert(y);
                    ring.push_back(x - ring.back());
                    ring.push_back(y - ring.back());
                }
                ring.pop_back(); // 0

                cout << "YES\n";
                print_except(excl, 0);
                for (int x : ring) {
                    cout << x << ' ';
                }
                cout << '\n';
                exit(0);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    two_same();
    even_odd();
    all_odd();
    no();
}