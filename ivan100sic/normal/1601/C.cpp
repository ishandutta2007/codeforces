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

int n, m;
int a[1000005], b[1000005], pos[1000005], c[2000005], ck;
ll sol = 0;

void solve(int al, int ar, int bl, int br) {
    if (bl > br) return;

    int bm = midpoint(bl, br);
    int y = b[bm];
    int c = 0, lo = 0, aopt = al;
    for (int i : ra(al, ar)) {
        // y a[i] -> a[i] y
        if (y > a[i]) {
            c--;
        } else if (y < a[i]) {
            c++;
        }

        if (c < lo) {
            lo = c;
            aopt = i+1;
        }
    }
    pos[bm] = aopt;

    solve(al, aopt, bl, bm-1);
    solve(aopt, ar, bm+1, br);
}

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
        for (; p; p -= p & -p)
            v = f(v, a[p-1]);
        return v;
    }
};

template<class T>
struct compressor {
    vector<T*> v;
    T b;
    compressor(T b = T()) : b(b) {}
    void operator+=(T& x) { v.push_back(&x); }
    int operator()() {
        if (v.empty()) return 0;
        sort(v.begin(), v.end(), [](T* x, T* y) { return *x < *y; });
        T p = *v[0];
        *v[0] = b;
        T w = b;
        int q = 1;
        for (size_t i=1; i<v.size(); i++) {
            if (*v[i] != p) ++w, ++q;
            p = *v[i];
            *v[i] = w;
        }
        return q;
    }
};

ll invs() {
    compressor<int> cp;
    for (int i : ra(0, ck)) {
        cp += c[i];
    }
    cp();
    fenwick<int> fw(ck + 2);
    ll z = 0;
    dbg(vector(c, c+ck));
    for (int i : ra(0, ck)) {
        z += i - fw(c[i] + 1);
        fw.add(c[i], 1);
    }
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i : ra(0, n)) cin >> a[i];
        for (int i : ra(0, m)) cin >> b[i];
        R::sort(b, b+m);
        solve(0, n, 0, m-1);

        dbg(vector(pos, pos+m));
        ck = 0;
        int j = 0;
        for (int i : ra(0, n)) {
            while (j < m && pos[j] == i) {
                c[ck++] = b[j++];
            }
            c[ck++] = a[i];
        }
        while (j < m) {
            c[ck++] = b[j++];
        }

        cout << invs() << '\n';
    }
    
}