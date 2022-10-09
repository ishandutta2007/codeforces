// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

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

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    R::reverse(a);

    vector<ll> q(2*n+5);

    ll sol = 0, u = 0, v = 0, rest = 0;
    for (int i : ra(0, n)) {
        u += q[i];
        if (i >= n-k) {
            v += u;
            ll d = max(0ll, a[i] - v);
            d = (d+(n-i)-1) / (n-i);
            rest = max(rest, d);
            dbg(tuple(i, d));
        } else {
            ll d = max(0ll, a[i] - (u+v));
            d = (d+k-1) / k;
            sol += d;
            dbg(tuple(i, d));
            u += d*k;
            v += u;
            q[i+1] -= d*(k+1);
            q[i+k+1] += d;
        }
    }

    cout << sol + rest << '\n';
}

//  96 39 42 25 81 17 50
//- 32
//   0  0 10 25 81 17 50
//-        4
//         0 17 79 17 50
//-           6
//            0 67 11 50
//r             23  6 50