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

vector<int> a_g;

struct node : array<int, 2> {
    vector<int> id;

    int count_select(int l, int r, int& sel) {
        auto lit = R::lower_bound(id, l);
        auto rit = R::upper_bound(id, r);
        if (lit != rit) {
            sel = a_g[*lit];
        }
        return rit - lit;
    }
};

struct btrie {
    vector<node> a;
    
    btrie() : a(2) {}

    int nn() {
        int r = ssize(a);
        a.emplace_back();
        return r;
    }

    void add(int x, int id) {
        int t = 1;
        for (int i=29; i>=0; i--) {
            a[t].id.push_back(id);
            int b = 1 & (x >> i);
            if (!a[t][b]) {
                int nd = nn();
                a[t][b] = nd;
            }
            t = a[t][b];
        }
        a[t].id.push_back(id);
    }

    int solve(int l, int r) {
        int t = 1, sol = 0;
        vector<int> aux;
        
        for (int i=29; i>=0; i--) {
            int sel;
            int c0 = a[t][0] ? a[a[t][0]].count_select(l, r, sel) : 0;
            dbg(i);
            int c = c0 + R::count_if(aux, [&](int w) {
                int mask = sol + (1 << i) - 1;
                dbg(tuple(sol, mask, w));
                return (mask | w) == mask;
            });

            dbg(tuple(c0, c));

            if (c >= 2) {
                // keep going left, nothing to do
                t = a[t][0];
            } else {
                // Must add sel if found
                if (c0 > 0) {
                    aux.push_back(sel);
                } 
                // go right
                t = a[t][1];
                sol |= 1 << i;
            }
        }

        return sol;
    }
};

void stress_test() {
    for (int mask : ra(0, 65536)) {
        vector<int> a;
        for (int i : ra(0, 16)) {
            if (mask & (1 << i)) {
                a.push_back(i);
            }
        }
        if (a.size() < 2) continue;
        a_g = a;
        int expected = 123123123;
        for (int i : ra(0, ssize(a))) {
            for (int j : ra(0, i)) {
                expected = min(expected, a[i] | a[j]);
            }
        }

        int actual;
        btrie b;
        for (int i : ra(0, ssize(a))) {
            b.add(a[i], i);
        }
        actual = b.solve(0, ssize(a) - 1);

        if (expected != actual) {
            cerr << "expected = " << expected << ", actual = " << actual << '\n';
            for (int x : a) cerr << x << ' ';
            cerr << '\n';
            exit(1);
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    // stress_test();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a_g.resize(n);
        btrie eng;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            a_g[i] = x;
            eng.add(x, i);
        }

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << eng.solve(l, r) << '\n';
        }
    }
}