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

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const { return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 1000 * 1000 * 1000 + 7;
typedef modint<mod> mint;
mint operator""_mi(ull x) {
    return x;
}

int solve3(int sum, const vector<int>& f) {
    int c[3] = {0, 0, 0};
    for (int i : ra(1, 9)) {
        c[i % 3] += f[i];
    }

    int z = sum / 3 - c[0];
    z += abs(c[1] - c[2]) / 3;
    return z;
}

const vector<vector<int>> w1 = {
    {1},
};

const vector<vector<int>> w2 = {
    {2},
    {1, 1},
};

const vector<vector<int>> w22 = {
    {1, 1, 2},
    {2, 2},
    {1, 1, 1, 1},
};

const vector<vector<int>> w4 = {
    {4},
    {3, 1},
    {1, 1, 2},
    {2, 2},
    {1, 1, 1, 1},
};

vector<vector<int>> gen_tuples(int len) {
    int pw = 1 << (3*len);
    vector<vector<int>> result;
    for (int i : ra(0, pw)) {
        vector<int> a(len);
        int tmp = i;
        for (int j : ra(0, len)) {
            a[j] = (tmp & 7) + 1;
            tmp >>= 3;
        }
        result.push_back(a);
    }
    return result;
}

int solve(int n, const vector<int>& a) {
    vector<int> ft(9);
    for (int x : a) {
        if (x < 6) ft[x]++;
        else ft[6+x%3]++;
    }

    auto run_once = [&](int decr, auto& ww, int cw) {
        int best = 1e9;
        for (auto w : ww) {
            int k = ssize(w);
            for (auto tu : gen_tuples(k)) {
                bool valid = true;
                vector<int> take(9), give(9);
                for (int i : ra(0, k)) {
                    if (tu[i] - w[i] < 0) {
                        valid = false;
                        break;
                    }
                    take[tu[i]]++;
                    give[tu[i] - w[i]]++;
                }
                
                if (!valid) continue;
                auto f2 = ft;

                for (int i : ra(0, 9)) {
                    if (take[i] > ft[i]) {
                        valid = false;
                        break;
                    }
                    f2[i] -= take[i] - give[i];
                }

                if (!valid) continue;
                int sol3 = solve3(n-decr, f2);
                best = min(best, sol3 + 2*k - cw - f2[0]);
                if (best == 0) {
                    best = best;
                }
            }
        }
        return best;
    };

    if (n % 3 == 0) {
        return solve3(n, ft);
    } else if (n % 3 == 2) {
        return run_once(2, w2, 1);
    } else if (n == 1) {
        return 0;
    } else {
        return min({
            run_once(4, w4, 1),
            run_once(4, w22, 2),   
        });
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int& x : p) cin >> x, x--;
        vector<int> vis(n), lens;
        for (int i : ra(0, n)) {
            if (!vis[i]) {
                vis[i] = 1;
                int len = 1;
                for (int j=p[i]; j!=i; j=p[j]) {
                    vis[j] = 1;
                    len++;
                }
                lens.push_back(len);
            }
        }

        mint w = 1;
        if (n % 3 == 0) {
            w = 3_mi ^ (n/3);
        } else if (n % 3 == 1) {
            if (n == 1) {
                w = 1;
            } else {
                w = 3_mi ^ (n/3-1);
                w *= 4;
            }
        } else {
            w = 3_mi ^ (n/3);
            w *= 2;
        }

        int sol = solve(n, lens);
        cout << w() << ' ' << sol << '\n';
    }
}