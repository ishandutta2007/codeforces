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

struct bipartite_union_find {
    vector<int> p, c;

    bipartite_union_find(int n) : p(n), c(n) {
        iota(p.begin(), p.end(), 0);
    }

    pair<int, int> ep(int x) {
        if (p[x] == x) return {x, 0};
        auto t = ep(p[x]);
        p[x] = t.first;
        c[x] ^= t.second;
        return {p[x], c[x]};
    }

    int join(int x, int y, int w) {
        int cx, cy;
        tie(x, cx) = ep(x);
        tie(y, cy) = ep(y);

        if (x == y) {
            return w ^ cx ^ cy ? -1 : 0;
        }

        p[x] = y;
        c[x] = w ^ cx ^ cy;
        return 1;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector a(n, vector(n, 0));

        for (int i : ra(0, n)) {
            for (int j : ra(0, n)) {
                cin >> a[i][j];
            }
        }

        bipartite_union_find buf(n);

        for (int i : ra(0, n)) {
            for (int j : ra(i+1, n)) {
                if (a[i][j] != a[j][i]) {
                    int w = a[i][j] > a[j][i];
                    int q = buf.join(i, j, w);
                }
            }
        }

        for (int i : ra(0, n)) {
            if (buf.ep(i).second) {
                for (int j : ra(0, n)) {
                    swap(a[i][j], a[j][i]);
                }
            }
        }

        for (int i : ra(0, n)) {
            for (int j : ra(0, n)) {
                cout << a[i][j] << " \n"[j == n-1];
            }
        }
    }
}