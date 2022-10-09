// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const {	return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

int c[2][1000005][2], n, m;
int bad[2], occ[2];
int ckb[2];
map<pair<int, int>, bool> mp;

void change(int x, int y, int t, int v) {
    t ^= (x + y) % 2;
    bad[0] -= c[0][x][0] && c[0][x][1];
    bad[1] -= c[1][y][0] && c[1][y][1];
    
    occ[0] -= c[0][x][0] || c[0][x][1];
    occ[1] -= c[1][y][0] || c[1][y][1];

    c[0][x][t] += v;
    c[1][y][t] += v;
    ckb[t] += v;

    bad[0] += c[0][x][0] && c[0][x][1];
    bad[1] += c[1][y][0] && c[1][y][1];

    occ[0] += c[0][x][0] || c[0][x][1];
    occ[1] += c[1][y][0] || c[1][y][1];
}

void rm(int x, int y, int t) {
    change(x, y, t, -1);
}

void ad(int x, int y, int t) {
    change(x, y, t, 1);
}

mint solve() {
    if (bad[0] && bad[1]) return 0;
    // nema nista nigde
    if (ckb[0] + ckb[1] == 0) {
        return (mint(2) ^ n) + (mint(2) ^ m) - 2;
    }

    // neka vrsta se ne uklapa
    if (bad[0]) {
        return mint(2) ^ (m - occ[1]);
    }

    // neka kolona se ne uklapa
    if (bad[1]) {
        return mint(2) ^ (n - occ[0]);
    }

    // svi su iste boje
    if (ckb[0] == 0 || ckb[1] == 0) {
        return (mint(2) ^ (m - occ[1])) + (mint(2) ^ (n - occ[0])) - 1;
    }

    mint z = (mint(2) ^ (m - occ[1])) + (mint(2) ^ (n - occ[0]));
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int k;
    cin >> n >> m >> k;

    while (k--) {
        int x, y, t;
        cin >> x >> y >> t;
        if (t == -1) {
            if (auto it = mp.find({x, y}); it != mp.end()) {
                rm(x, y, it->second);
                mp.erase(it);
            }
        } else {
            if (auto it = mp.find({x, y}); it != mp.end()) {
                rm(x, y, it->second);
                mp.erase(it);
            }

            mp[{x, y}] = t;
            ad(x, y, t);
        }

        cout << solve()() << '\n';
    }
}