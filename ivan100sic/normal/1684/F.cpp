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

        // input array
        vector<int> a(n);
        for (int& x : a) cin >> x;

        // uqlen[l]: largest w such that suffix of a[..r] of length w has unique values
        vector uqlen(n, 0);
        {
            set<int> s;
            int l = 0;
            for (int i : ra(0, n)) {
                while (s.contains(a[i])) {
                    s.erase(a[l++]);
                }
                s.insert(a[i]);
                uqlen[i] = ssize(s);
            }
        }
        
        vector<vector<int>> segr(n);

        // sreach[l]: largest r such that there is a segment that contains l and r
        // or -1 if it doesn't exist
        vector<int> sreach(n, -1);
        {
            for (int i : ra(0, m)) {
                int l, r;
                cin >> l >> r;
                l--, r--;
                segr[l].push_back(r);
                sreach[l] = max(sreach[l], r);
            }
            for (auto& v : segr) {
                R::sort(v);
            }
            for (int i : ra(1, n)) {
                sreach[i] = max(sreach[i], sreach[i-1]);
                if (sreach[i] < i) {
                    sreach[i] = -1;
                }
            }
        }

        map<int, vector<int>> pos;
        for (int i : ra(0, n)) {
            pos[a[i]].push_back(i);
        }

        // xreach[l]: largest r such that there is a segment that contains l and r
        // and a[l] = a[r] and r > l, or -1 if such a segment doesn't exist
        vector<int> xreach(n);
        {
            for (int l : ra(0, n)) {
                int r = sreach[l];
                if (r == -1) {
                    xreach[l] = -1;
                    continue;
                }
                int x = a[l];
                auto it = R::lower_bound(pos[x], r+1) - 1;
                int j = *it;
                xreach[l] = j == l ? -1 : j;
            }
        }

        // s2: minimum r such that segments only end up having unique values
        // when everything up to and including r is deleted
        // or -1 if there are no such segments
        int s2 = -1;
        {
            for (int l : ra(0, n)) {
                for (int r : segr[l]) {
                    int j = r - uqlen[r];
                    s2 = max(s2, j);
                }
            }
        }

        // badl: smallest l such that there are x, y such that a[x] = a[y],
        // x < y < l and some segment contains x, y

        // therefore in the solution l < badl must hold
        int badl = n;
        for (int i : ra(0, n)) {
            int x = a[i];
            auto it = R::lower_bound(pos[x], i+1);
            if (it != end(pos[x])) {
                int j = *it;
                if (sreach[i] >= j) {
                    badl = min(badl, j + 1);
                }
            }
        }

        // solve at last
        int sol = n, s1 = -1;
        for (int l : ra(0, badl)) {
            int s = max(s1, s2);
            sol = min(sol, max(0, s-l+1));
            s1 = max(s1, xreach[l]);
        }

        dbg(uqlen);
        dbg(sreach);
        dbg(xreach);
        dbg(s2);
        dbg(badl);

        cout << sol << '\n';
    }
}