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
using mint = modint<mod>;

mint brut(vector<int> a) {
    mint sum = 0;
    int n = a.size();
    for (int mask=0; mask<(1<<(n-1)); mask++) {
        mint prod = 1;
        int mn = a[0];
        for (int i=0; i<n-1; i++) {
            if (mask & (1 << i)) {
                mn = min(mn, a[i+1]);
            } else {
                prod *= -mn;
                mn = a[i+1];
            }
        }
        prod *= -mn;
        sum += prod;
    }
    return sum;
}

struct entry {
    int l, r, v;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<mint> d(n+1), z(n+2);
    d[0] = z[1] = 1;    

    vector<entry> st;
    mint sum = 0;
    for (int i=0; i<n; i++) {
        int sl = i, sr = i + 1, x = a[i];
        while (st.size() && x <= st.back().v) {
            auto [l, r, v] = st.back();
            st.pop_back();
            sum -= (z[r] - z[l]) * -v; 
            sl = l;
        }

        st.push_back({sl, sr, x});
        sum += (z[sr] - z[sl]) * -x;
        d[i+1] = sum;
        z[i+2] = z[i+1] + d[i+1];
    }

    if (n % 2) sum *= -1;
    cout << sum() << '\n';
}