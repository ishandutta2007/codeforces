// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

namespace debug {
    const char yellow[] = "\x1b[33m";
    const char magenta[] = "\x1b[35m";
    const char blue[] = "\x1b[36m";
    const char green[] = "\x1b[32m";
    const char reset[] = "\x1b[0m";
    const char bold[] = "\x1b[1m";

    template<class T>
    auto debug(const T& x) -> decltype(cerr << x, 0) {
        return cerr << green << x << reset, 0; 
    }

    int debug(const string& x) {
        return cerr << yellow << '"' << x << '"' << reset, 0;
    }

    template<size_t i, class T>
    int debug_tuple(const T& x) {
        constexpr size_t n = tuple_size<T>::value;
        if (i == 0) {
            cerr << '(';
        }
        debug(get<i>(x));
        if constexpr (i == n - 1) {
            cerr << ')';
        } else {
            cerr << ", ";
            debug_tuple<i+1>(x);
        }
        return 0;
    }

    template<class T>
    auto debug(const T& x) -> decltype(debug(get<0>(x))) {
        return debug_tuple<0>(x);
    }

    template<class T>
    auto debug(const T& x) -> decltype(debug(*x.begin())) {
        cerr << '{';
        auto it = x.begin();
        while (1) {
            if (it == x.end()) {
                cerr << '}';
                return 0;
            } else {
                debug(*it);
                if (next(it) != x.end()) {
                    cerr << ", ";
                }
                ++it;
            }
        }
    }

    template<class T>
    void debug(int l, const T& x, const char* n) {
        cerr << magenta << "Line " << l << ": " << blue << bold << n << reset << " = ";
        debug(x);
        cerr << '\n';
    }
}

#ifdef LOCAL
    #define dbg(x) (debug::debug(__LINE__, x, #x))
#else
    #define dbg(x)
#endif

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

const int mod = 1'000'000'007;
typedef modint<mod> mint;

template<class T = mint>
struct binomial {
    vector<T> f, finv;

    binomial(int n) : f(n), finv(n) {
        f[0] = finv[0] = 1;
        for (int i=1; i<n; i++) {
            f[i] = f[i-1] * i;
            finv[i] = T(1) / f[i];
        }
    }

    T mix(ll a, ll b) {
        if (a < 0 || b < 0)
            return 0;
        return f[a+b] * finv[a] * finv[b];
    }

    T choose(ll n, ll k) {
        return mix(n-k, k);
    }
};

binomial bk(200005);

mint s(ll n, ll k, ll x) {
    mint b1 = bk.choose(n+x-k*x-2, n-k*x-1);
    mint b2 = bk.choose(n+x-k*x-k-1, n-k*x-k);

    mint p = (b1*(-1 + n - k*x)*(-1 + n + x - k*x)*(n + x - k*x) + b2*(-1 + k - n + (-1 + k)*x)*(k - n + (-1 + k)*x)*(k - n + k*x))*2;
    mint q = bk.choose(n, 1 + x)*(-1 + n - x)*x;

    return p / q;
}

mint s0(ll n, ll k) {
    mint p = 2*(k-1)*(2*n-k);
    mint q = n*(n-1);

    return p / q;
}

mint d(ll n, ll k, ll x) {
    ll mn = min(n-1, 2*k-2);
    mint b1 = bk.choose(-1-k+n+x-k*x, -k+n-k*x);
    mint b2 = bk.choose(-2+n+x-k*x-mn, -1+n-k*x-mn);
    mint b3 = bk.choose(n, 2+x);

    mint p = (b2*(mn - n + (-1 + k)*x)*(1 + mn - n + (-1 + k)*x)*(1 + mn - n + 
        k*x)*(4 + 2*mn + n + (2 + mn)*x - 3*k*(2 + x)) + 
        b1*(-1 + k - n + (-1 + k)*x)*(k - n + (-1 + k)*x)*(k - n + 
        k*x)*(-2 - n - x + 2*k*(2 + x)));

    mint q = b3*(-2 + n - x)*x*(2 + x);

    return p/q*(-1);
}

mint d0(ll n, ll k) {
    ll mn = min(n-1, 2*k-2);
    mint p = (-1 + k - mn)*(4*k*k + k*(-2 + 4*mn - 9*n) - (2 + mn)*(2*mn - 3*n));
    mint q = n*(n-1)*(n-2);

    return p/q;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        mint sol;

        ll n, k;
        cin >> n >> k;

        sol += s0(n, k);
        for (ll x=1; x<=n-2; x++) {
            sol += s(n, k, x);
        }

        sol += d0(n, k);
        for (ll x=1; x<=n-3; x++) {
            sol += d(n, k, x);
        }

        cout << sol() << '\n';
    }
}