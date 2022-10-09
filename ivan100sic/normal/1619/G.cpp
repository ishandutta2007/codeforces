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

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

struct mine {
    int x, y, t;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<mine> a(n);
        for (auto& [x, y, t] : a) {
            cin >> x >> y >> t;
        }

        map<int, vector<pair<int, int>>> mx, my;
        vector<vector<int>> e(n);
        for (int i : ra(0, n)) {
            auto [x, y, _t] = a[i];
            mx[x].emplace_back(y, i);
            my[y].emplace_back(x, i);
        }

        for (auto p : {&mx, &my}) {
            for (auto& [key, v] : *p) {
                R::sort(v);
                // dbg(v);
                for (int i : ra(0, ssize(v) - 1)) {
                    auto [p1, i1] = v[i];
                    auto [p2, i2] = v[i+1];
                    if (p2 - p1 <= k) {
                        // dbg(pair(i1, i2));
                        e[i1].push_back(i2);
                        e[i2].push_back(i1);
                    }
                }
            }
        }
        
        vector<int> col(n, -1); int cc = 0;
        for (int i : ra(0, n)) {
            if (col[i] == -1) {
                col[i] = cc;
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int i = q.front(); q.pop();
                    for (int j : e[i]) {
                        if (col[j] == -1) {
                            col[j] = cc;
                            q.push(j);
                        }
                    }
                }
                cc++;
            }
        }

        dbg(cc);

        cout << *R::lower_bound(ra(0, n+3), true, {}, [&](int m) {
            set<int> boom;
            for (int i : ra(0, n)) {
                if (a[i].t <= m) {
                    boom.insert(col[i]);
                }
            }

            return cc - ssize(boom) <= m + 1;
        }) << '\n';
    }
}