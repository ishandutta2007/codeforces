// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, q;
unsigned m;

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
    bool operator!= (const modint& other) const { return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

using mint = modint;

mint a[300005], fib[300005];
int c0;

void invert() {
    for (int i=n-1; i>=2; i--) {
        a[i] -= a[i-1] + a[i-2];
    }
    a[1] -= a[0];
}

template<int w, class... T>
void chx(T... idx) {
    auto f = [](int i) {
        if (i < n && a[i] == 0) {
            c0 += w;
        }
    };

    (f(idx), ...);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q >> m;
    for (int d : {1, -1}) {
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            a[i] += d * x;
        }
    }

    fib[1] = 1;
    for (int i : ra(2, n+3)) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    invert();

    c0 = count(a, a+n, 0);
    while (q--) {
        int l, r;
        char c;
        cin >> c >> l >> r;
        l--, r--;
        int d = c == 'A' ? 1 : -1;
        chx<-1>(l, r+1, r+2);
        a[l] += d;
        a[r+1] -= fib[r-l+2] * d;
        a[r+2] -= fib[r-l+1] * d;
    
        chx<1>(l, r+1, r+2);

        cout << (c0 == n ? "YES\n" : "NO\n");
    }
}