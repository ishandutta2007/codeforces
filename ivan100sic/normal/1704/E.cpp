// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<unsigned m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(unsigned arg) {
        if (arg < 2*m) {
            x = arg;
        } else {
            x = arg % m + m;
        }
    }

    modint operator+ (const modint& b) const {
        auto t = *this;
        t.x += b.x;
        if (t.x >= 3*m) t.x -= 2*m;
        else if (t.x >= 2*m) t.x -= m;
        return t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const { return x != other.x; }
    unsigned operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

template<class F, class K, class... A>
auto I(F f, K k, A... a) {
    return f(k, forward<A>(a)...) - begin(k);
}

struct rng {
    unsigned start;
    mint len;

    bool operator< (const rng& o) const {
        return start < o.start;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<unsigned> a(n);
        for (unsigned& x : a) cin >> x;

        vector<vector<int>> e(n), f(n);
        vector<int> deg(n), indeg(n);
        for (int i : ra(0, m)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x].push_back(y);
            f[y].push_back(x);
            deg[x]++;
            indeg[y]++;
        }

        const int sink = I(R::find, deg, 0);

        vector<int> topo;
        int qs = 0;
        for (int x : ra(0, n)) {
            if (indeg[x] == 0) {
                topo.push_back(x);
            }
        }

        while (qs != ssize(topo)) {
            int x = topo[qs++];
            for (int y : e[x]) {
                if (0 == --indeg[y]) {
                    topo.push_back(y);
                }
            }
        }

        vector<vector<rng>> dp(n);
        for (int x : topo) {
            vector<rng> tmp;
            if (a[x] > 0) {
                tmp.push_back({0, a[x]});
            }

            for (int y : f[x]) {
                for (auto [s, l] : dp[y]) {
                    tmp.push_back({s + 1, l});
                }
            }

            R::sort(tmp, less<>{});

            auto& d = dp[x];
            for (auto [s, l] : tmp) {
                if (d.size() && d.back().start + d.back().len() >= s) {
                    d.back().len += l;
                } else {
                    d.push_back({s, l});
                }
            }

            // cerr << x << ' ';
            // for (auto [s, l] : tmp) cerr << "(" << s << " " << l() << ") ";
            // cerr << '\n';
        }

        if (dp[sink].size()) {
            auto& z = dp[sink].back();
            cout << (z.start + z.len()) % mod << '\n';
        } else {
            cout << "0\n";
        }
    }
}