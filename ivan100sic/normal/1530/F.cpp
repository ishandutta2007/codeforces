// Retired?
#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
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
        auto t = *this; t.x = (t.x) * b.x % m; return t;
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

const int mod = 31'607;
typedef modint<mod> mint;

int n;
int a[21][21];

void sos(mint* a, int m) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<(1<<m); j++) {
            if (j & (1 << i)) {
                a[j] += a[j - (1 << i)];
            }
        }
    }
}


void sos(mint* a) {
    sos(a, n+2);
}

void antisos(mint* a) {
    int m = n + 2;
    for (int i=0; i<m; i++) {
        for (int j=(1<<m)-1; j>=0; j--) {
            if (j & (1 << i)) {
                a[j] -= a[j - (1 << i)];
            }
        }
    }
}

void or_conv_slow(mint* a, mint* b, mint* c) {
    int m = n + 2;
    for (int i=0; i<(1<<m); i++) {
        c[i] = 0;
    }

    for (int i=0; i<(1<<m); i++) {
        for (int j=0; j<(1<<m); j++) {
            c[i|j] += a[i] * b[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    vector<mint> v(4 << n, 0);
    v[0] = 1;
    sos(v.data());

    for (int i=0; i<n; i++) {
        auto b = a[i];
        vector<mint> v2(1 << n, 0);
        for (int mask=1; mask<(1<<n); mask++) {
            mint p = 1;
            for (int j=0; j<n; j++) {
                if (mask & (1 << j)) {
                    p *= 10000 - b[j];
                } else {
                    p *= b[j];
                }
            }

            v2[mask] = p;
        }

        sos(v2.data(), n);

        vector<mint> v3(4 << n);

        if (i == n-1-i) {
            for (int mask=0; mask<(1<<n); mask++) {
                int ext_mask = mask;
                if (mask & (1 << i)) {
                    ext_mask |= 3 << n;
                }

                if (mask != ext_mask) {
                    v3[ext_mask] = v2[mask];
                    mint t = v2[mask - (1 << i)];
                    v3[mask] = t;
                    v3[mask | (1 << n)] = t;
                    v3[mask | (2 << n)] = t;
                } else {
                    mint t = v2[mask];
                    v3[mask | (3 << n)] = t;
                    v3[mask | (2 << n)] = t;
                    v3[mask | (1 << n)] = t;
                    v3[mask | (0 << n)] = t;
                }
            }
        } else {
            for (int mask=0; mask<(1<<n); mask++) {
                int m1 = 1 << i;
                int m2 = 1 << (n - 1 - i);
                if ((mask & m1) && (mask & m2)) {
                    v3[mask | (3 << n)] = v2[mask];
                    v3[mask] = v2[mask - m1 - m2];
                    v3[mask | (1 << n)] = v2[mask - m2];
                    v3[mask | (2 << n)] = v2[mask - m1];
                } else if (mask & m1) {
                    v3[mask | (3 << n)] = v2[mask];
                    v3[mask | (1 << n)] = v2[mask];
                    mint t = v2[mask - m1];
                    v3[mask] = t;
                    v3[mask | (2 << n)] = t;
                } else if (mask & m2) {
                    v3[mask | (3 << n)] = v2[mask];
                    v3[mask | (2 << n)] = v2[mask];
                    mint t = v2[mask - m2];
                    v3[mask] = t;
                    v3[mask | (1 << n)] = t;
                } else {
                    mint t = v2[mask];
                    v3[mask | (3 << n)] = t;
                    v3[mask | (2 << n)] = t;
                    v3[mask | (1 << n)] = t;
                    v3[mask | (0 << n)] = t;
                }
            }
        }

        for (int i=0; i<(4<<n); i++) {
            v[i] *= v3[i];
        }        
    }

    antisos(v.data());

    cerr << "info " << v[(4 << n) - 1]() << '\n';
    cout << (mint(1) - v[(4 << n) - 1] / (mint(10000) ^ (n * n)))() << '\n';
}

/*
21
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/