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

template<class T = int, class F = plus<T>>
struct fenwick {
    vector<T> a;
    T e;
    F f;

    fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

    void add(int p, const T& v) {
        for (p++; p <= (int)a.size(); p += p & -p)
            a[p-1] = f(a[p-1], v);
    }

    T operator() (int p) const {
        T v = e;
        p = min(p, (int)a.size());
        for (; p > 0; p -= p & -p)
            v = f(v, a[p-1]);
        return v;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        map<int, int> mp;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            mp[x]++;
        }

        int sol = 1e9;

        vector<int> sorted_sizes;
        vector<vector<int>> size_to_pos(n+1);
        for (auto [k, v] : mp) {
            sorted_sizes.push_back(v);
        }
        R::sort(sorted_sizes);
        for (int i : ra(0, ssize(sorted_sizes))) {
            size_to_pos[sorted_sizes[i]].push_back(i);
        }
        fenwick<int> cnt(n+1);
        fenwick<ll> sum(n+1);

        for (int i : ra(0, ssize(sorted_sizes))) {
            int x = sorted_sizes[i];
            cnt.add(i, 1);
            sum.add(i, x);
        }

        auto water = [&]() {
            int m = -1 + *R::lower_bound(ra(0, n+1), true, {}, [&](int m) {
                return sum(m) > k;
            });
            return cnt(m);
        };

        // zeros in mex area
        int gaps = 0;

        int diff = ssize(mp);

        for (int mex=0; mex<=n; mex++) {
            if (gaps <= k) {
                int w = water();
                dbg(tuple(mex, diff, w, gaps));
                sol = min(sol, max(1, diff-w+gaps) - mex);
            }
            // update
            if (auto it = mp.find(mex); it != mp.end()) {
                int x = it->second;
                int j = size_to_pos[x].back();
                size_to_pos[x].pop_back();
                cnt.add(j, -1);
                sum.add(j, -x);
            } else {
                gaps++;
            }
        }

        cout << sol << '\n';
    }
}