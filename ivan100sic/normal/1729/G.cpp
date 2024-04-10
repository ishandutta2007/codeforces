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

const int mod = 1000 * 1000 * 1000 + 7;
typedef modint<mod> mint;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;

        const int n = ssize(s);
        const int m = ssize(t);

        vector<int> p;
        for (int i=0; i<=n-m+1; i++) {
            if (string_view(s).substr(i, m) == string_view(t)) {
                p.push_back(i);
            }
        }

        const int k = ssize(p);
        
        if (k == 0) {
            cout << "0 1\n";
            continue;
        }
        
        vector<int> d(k+1, 123123123);
        vector<mint> ways(k+1);
    
        auto add = [&](int i, int v, mint w) {
            if (v < d[i]) {
                d[i] = v;
                ways[i] = w;
            } else if (v == d[i]) {
                ways[i] += w;
            }
        };

        for (int i : ra(0, k)) {
            // Can it be first?
            if (p[i] - p[0] < m) {
                add(i, 1, 1);
            }

            int fr = -1;
            for (int j=i-1; j>=0; j--) {
                if ((fr == -1 || fr - p[j] < m) && p[i] - p[j] >= m) {
                    add(i, d[j]+1, ways[j]);
                }

                if (fr == -1 && p[i] - p[j] >= m) {
                    fr = p[j];
                }
            }

            // Can it be last?
            if (p[k-1] - p[i] < m) {
                add(k, d[i], ways[i]);
            }
        }

        cout << d[k] << ' ' << ways[k]() << '\n';
    }
}