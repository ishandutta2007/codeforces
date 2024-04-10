// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
constexpr auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int, class F = plus<T>>
struct fenwick {
    vector<T> a;
    T e;
    F f;

    fenwick(int n = 0, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

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

const int Acc = 40;

template<class T>
struct lump {
    T a[Acc];

    template<class U>
    lump(const lump<U>& u) { R::copy(u.a, a); }

    lump() {
        R::fill(a, T(0));
    }

    lump operator+ (const lump& b) const {
        lump result;
        for (int i : ra(0, Acc)) {
            result.a[i] = a[i] + b.a[i];
        }
        return result;
    }

    lump operator- (const lump& b) const {
        lump result;
        for (int i : ra(0, Acc)) {
            result.a[i] = a[i] - b.a[i];
        }
        return result;
    }
};

struct query {
    int t, i, j, k;
};

int n, q;
int a[300005];
query u[300005];

int b[600005], bl;
lump<int> mp[600005];

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

const int bigi = 2'100'000'000;
uid ran(-bigi, bigi);

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q;
    for (int i : ra(0, n)) {
        cin >> a[i];
        b[i] = a[i];
    }
    bl = n;

    fenwick<lump<ll>> f(n+2);

    for (int iq : ra(0, q)) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            b[bl++] = x;
            u[iq] = {t, i, x, -1};
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            u[iq] = {t, l, r, k};
        }
    }

    sort(b, b+bl);
    bl = unique(b, b+bl) - b;

    for (int i : ra(0, bl)) {
        for (int j : ra(0, Acc)) {
            mp[i].a[j] = ran(eng);
        }
    }

    for (int i : ra(0, n)) {
        int mpi = lower_bound(b, b+bl, a[i]) - b;
        f.add(i, mp[mpi]);
    }

    for (auto [t, p, q, r] : span(u, u+q)) {
        if (t == 1) {
            int oli = lower_bound(b, b+bl, a[p]) - b;
            int nui = lower_bound(b, b+bl, q) - b;

            a[p] = q;
            f.add(p, lump<ll>(mp[nui]) - lump<ll>(mp[oli]));
        } else {
            bool ok = 1;
            auto z = f(q) - f(p);

            for (int j : ra(0, Acc)) {
                if (z.a[j] % r) {
                    ok = 0;
                    break;
                }
            }

            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}