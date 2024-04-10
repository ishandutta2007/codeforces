// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T, bool maximize = false>
struct lichao {
    struct line {
        T k, b;
        T operator() (T x) const { return k*x + b; }
    };

    int l;
    vector<line> a;

    lichao(int l, int r) : l(l) {
        int maxn = 1;
        while (maxn < r-l)
            maxn <<= 1;
        a.assign(2*maxn, line{0, numeric_limits<T>::max()});
    }

    void add(line p, int x, int xl, int xr) {
        if (a[x](l+xl) <= p(l+xl) && a[x](l+xr) <= p(l+xr))
            return;
        if (p(l+xl) <= a[x](l+xl) && p(l+xr) <= a[x](l+xr)) {
            a[x] = p;
            return;
        }
        if (p(l+xl) < a[x](l+xl))
            swap(p, a[x]);
        int xm = midpoint(xl, xr);
        add(p, 2*x  , xl  , xm);
        add(p, 2*x+1, xm+1, xr);
    }

    lichao& operator+= (line p) {
        if (maximize)
            p.k = -p.k, p.b = -p.b;
        add(p, 1, 0, (a.size()>>1)-1);
        return *this;
    }

    T operator() (int t) const {
        int x = t + (a.size() >> 1) - l;
        T v = a[0].b;
        for (; x; x >>= 1)
            v = min(v, a[x](t));
        return maximize ? -v : v;
    }
};

int n, m, k;
vector<pair<int, int>> e[100005];
ll d[100005];

void road() {
    set<pair<ll, int>> pq;
    for (int i : ra(0, n)) {
        pq.insert({d[i], i});
    }

    while (pq.size()) {
        auto [dx, x] = *pq.begin();
        pq.erase(pq.begin());
        for (auto [y, w] : e[x]) {
            if (d[y] > dx + w) {
                pq.erase({d[y], y});
                d[y] = dx + w;
                pq.insert({d[y], y});
            }
        }
    }
}

void flight() {
    lichao<ll> lc(0, n);
    for (int i : ra(0, n)) {
        lc += {-2*i, d[i] + 1ll*i*i};
    }

    for (int i : ra(0, n)) {
        d[i] = lc(i) + 1ll*i*i;
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> k;
    for (int i : ra(0, m)) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        e[x].emplace_back(y, w);
        e[y].emplace_back(x, w);
    }

    memset(d, 63, sizeof(d));
    d[0] = 0;

    for (int i : ra(0, k)) {
        road();
        flight();
    }
    road();

    for (int i : ra(0, n)) {
        cout << d[i] << " \n"[i == n-1];
    }
}