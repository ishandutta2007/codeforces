// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

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

    modint operator-() const {
        auto t = *this; t.x = x ? m-x : 0; return t; 
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
    bool operator!= (const modint& other) const { return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

int can[512][10];
bool g[10][10]; // allowed swaps
int n;

void rdi() {
    cin >> n;
    
    int m;
    cin >> m;
    for (int i : ra(0, m)) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
}

void pcp() {
    // mask[x] = 1 means x cannot be placed
    // to be more precise, the sequence ends with numbers, all swappable with x
    // such that one of them is greater than x

    for (int mask : ra(0, 512)) {
        for (int x : ra(0, 10)) {
            // can we place x?
            if (mask & (1 << x)) {
                can[mask][x] = -1;
                continue;
            }

            // what is the resulting mask?
            // can we place y after x?
            int mask2 = 0;
            for (int y : ra(0, 9)) {
                bool block;
                if (g[x][y]) {
                    block = (mask & (1 << y)) || (x > y);
                } else {
                    block = false;
                }

                if (block) {
                    mask2 |= 1 << y;
                }
            }

            can[mask][x] = mask2;
        }
    }
}

mint d[2][512];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    rdi();
    pcp();
    d[0][0] = 1;

    for (int i : ra(0, n)) {
        auto ol = d[i%2];
        auto nu = d[(i+1)%2];
        fill(nu, nu+512, mint{});

        for (int mask : ra(0, 512)) {
            for (int x : ra(0, 10)) {
                if (can[mask][x] != -1) {
                    nu[can[mask][x]] += ol[mask];
                }
            }
        }
    }

    cout << accumulate(d[n%2], d[n%2] + 512, mint{})() << '\n';
}