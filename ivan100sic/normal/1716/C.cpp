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

struct block {
    int len, hi;

    block() : len(0), hi(-2012012012) {}

    block(int x) : len(1), hi(x) {}

    block operator+ (const block& b) const {
        block c;
        c.len = len + b.len;
        c.hi = max(hi + b.len, b.hi);
        return c;
    }

    block& operator+= (const block& b) {
        return *this = *this + b;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<block> a[2], fwd[2], bck[2];

        for (int i : ra(0, 2)) {
            a[i].resize(n);
            for (int j : ra(0, n)) {
                int x;
                cin >> x;
                a[i][j] = x + (i || j);
            }

            fwd[i] = bck[i] = vector<block>(n+1);
            bck[i][1] = fwd[i][1] = a[i][n-1];
            for (int j : ra(2, n+1)) {
                fwd[i][j] = a[i][n-j] + fwd[i][j-1];
                bck[i][j] = bck[i][j-1] + a[i][n-j];
            }
        }

        block path;
        int sol = 2e9;
        for (int q : ra(1, 2*n-1)) {
            int x = q / 2 % 2;
            int y = (q - 1) / 2;

            path = path + a[x][y];
            int plen = n-1-y;
            int slen = 2*n-q-plen;

            block cand = path + fwd[x][plen] + bck[x^1][slen];
            sol = min(sol, cand.hi);

            dbg(tuple(q, x, y));
            dbg(tuple(path.hi, path.len));
            dbg(tuple(fwd[x][plen].hi, fwd[x][plen].len));
            dbg(tuple(bck[x^1][slen].hi, bck[x^1][slen].len));
            dbg(tuple(cand.hi, cand.len));
        }

        cout << sol << '\n';
    }
}

/*
1
4
0 10 10 10
10 10 10 10
*/