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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        vector<ll> z(n+1);
        for (int i : ra(0, n)) {
            z[i+1] = z[i] + (b[i] - a[i]);
        }

        set<int> nz;
        for (int i : ra(0, n+1)) {
            if (z[i]) {
                nz.insert(i);
            }
        }

        vector<vector<int>> ep(n+1);
        vector<pair<int, int>> seg(m);
        vector<int> pot(m);
        for (int j : ra(0, m)) {
            int l, r;
            cin >> l >> r;
            l--;
            ep[l].push_back(j);
            ep[r].push_back(j);
            seg[j] = {l, r};
            pot[j] = (z[l] != 0) + (z[r] != 0);
            dbg(tuple(j, pot[j]));
        }

        queue<int> q;
        for (int j : ra(0, m)) {
            if (pot[j] == 0) {
                q.push(j);
            }
        }

        while (!q.empty()) {
            int j = q.front(); q.pop();
            auto [l, r] = seg[j];
            auto it = nz.lower_bound(l);
            while (it != nz.end() && *it < r) {
                dbg(*it);
                for (int j2 : ep[*it]) {
                    if (0 == --pot[j2]) {
                        q.push(j2);
                    }
                }
                it = nz.erase(it);
            }
        }

        cout << (nz.empty() ? "YES\n" : "NO\n");
    }
    
}