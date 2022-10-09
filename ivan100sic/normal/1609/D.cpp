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

struct union_find_fat {
    vector<vector<int>> a;
    vector<int> b;
    set<int> r;

    union_find_fat(int n) : a(n), b(n) {
        for (int i=0; i<n; i++) {
            a[i] = {i};
            b[i] = i;
            r.emplace_hint(r.end(), i);
        }
    }

    bool join(int x, int y) {
        x = b[x];
        y = b[y];
        if (x == y) return false;
        if (a[x].size() > a[y].size()) swap(x, y);
        a[y].insert(a[y].end(), begin(a[x]), end(a[x]));
        for (int z : a[x]) b[z] = y;
        a[x].clear();
        r.erase(x);
        return true;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, d;
    cin >> n >> d;

    union_find_fat uff(n);
    int slack = 0;

    for (int i : ra(0, d)) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        int bx = uff.b[x];
        int by = uff.b[y];

        if (bx == by) {
            slack++;
        } else {
            uff.join(x, y);
        }

        vector<int> sz;
        for (int x : ra(0, n)) {
            if (uff.b[x] == x) {
                sz.push_back(uff.a[x].size());
            }
        }

        R::sort(R::reverse_view(sz));
        cout << accumulate(sz.begin(), sz.begin() + min((int)sz.size(), slack + 1), 0) - 1 << '\n';
    }
}