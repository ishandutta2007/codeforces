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
        int n, k;
        string s;
        cin >> n >> k >> s;
        
        int i = 1;
        char h = s[0];
        while (i < n && h - 'a' <= k) {
            h = max(h, s[i]);
            i++;
        }

        if (h - 'a' > k) {
            i--;
        }
        
        if (i > 0) {
            h = *max_element(s.begin(), s.begin() + i);
            for (int j : ra(0, n)) {
                if (s[j] <= h) {
                    s[j] = 'a';
                }
            }
            k -= h - 'a';
        }

        dbg(s);
        dbg(i);
        dbg(k);

        if (i < n) {
            while (k > 0) {
                char x = s[i];
                for (int j : ra(i, n)) {
                    if (s[j] == x) {
                        s[j]--;
                    }
                }
                k--;
            }
        }

        cout << s << '\n';
    }
}