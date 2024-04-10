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

struct op {
    int t, x;
};

const int maxn = 505;

int n;
op a[maxn];
mint d[2][2][maxn];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            a[i].t = 1;
            cin >> a[i].x;
        } else {
            a[i].t = -1;
        }
    }

    mint sol = 0;
    for (int idx=0; idx<n; idx++) {
        if (a[idx].t == -1) continue;
        memset(d, 0, sizeof d);
        d[0][0][0] = 1;
        for (int i=0; i<n; i++) {
            auto nu = d[(i+1) % 2];
            memset(nu, 0, sizeof(d[0]));
            auto ol = d[i % 2];
            for (int j : {0, 1}) {
                for (int k=0; k<=i; k++) {
                    if (ol[j][k] == 0) continue;
                    int j2, k2;
                    if (a[i].t == -1) {
                        if (k > 0) {
                            k2 = k - 1;
                            j2 = j;
                        } else {
                            k2 = 0;
                            j2 = 0;
                        }
                    } else {
                        if (i == idx) {
                            j2 = 1;
                            k2 = k;
                        } else {
                            if (tie(a[i].x, i) < tie(a[idx].x, idx)) {
                                k2 = k + 1;
                                j2 = j;
                            } else {
                                k2 = k;
                                j2 = j;
                            }
                        }
                    }
                    nu[j2][k2] += ol[j][k];
                    nu[j][k] += ol[j][k];
                }
            }
        }
        sol += accumulate(d[n%2][1], d[n%2][1] + n, mint(0)) * a[idx].x;
    }
    cout << sol() << '\n';
}