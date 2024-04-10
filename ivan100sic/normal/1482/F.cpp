// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

using ui = uint32_t;

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

struct rac {
    ll p, q;

    strong_ordering operator<=> (const rac& b) const {
        return p*b.q <=> q*b.p;
    }

    bool operator== (const rac& b) const {
        return (*this <=> b) == 0;
    }

    rac inv() const {
        return {q, p};
    }
};

ui rev(ui x) {
    ui y = 0;
    while (x) {
        y = 10 * y + x % 10;
        x /= 10;
    }
    return y;
}

rac a[100005];
fenwick<ll> fen(100005);
map<rac, vector<int>> loc;

int count_leq(int val, int bar) {
    auto it = loc.find(a[val]);
    if (it == loc.end()) return 0;
    const auto& v = it->second;
    return R::upper_bound(v, bar) - v.begin();
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll n, m, w;
    cin >> n >> m >> w;

    ll min_prod = 1e18, ox = -1, oy = -1;

    for (int i : ra(1, max(n, m) + 1)) {
        a[i] = rac{i, rev(i)};
        loc[a[i].inv()].push_back(i);
    }

    ll y = m, cnt = 0;
    for (ll x : ra(1, n+1)) {
        // add (x, 1) ... (x, y)
        cnt += count_leq(x, y);

        // reduce y while you can
        while (1) {
            const auto& lay = loc[a[y]];
            ll diff = count_leq(y, x);
            if (cnt - diff < w) {
                break;
            }

            cnt -= diff;
            y--;
        }

        if (cnt >= w) {
            if (x*y < min_prod) {
                min_prod = x*y;
                ox = x;
                oy = y;
            }
        }
    }

    if (ox != -1) {
        cout << ox << ' ' << oy << '\n';
    } else {
        cout << "-1\n";
    }
}