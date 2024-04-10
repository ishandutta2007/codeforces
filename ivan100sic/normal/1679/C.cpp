// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

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
        p = min(p, (int)a.size());
        for (; p > 0; p -= p & -p)
            v = f(v, a[p-1]);
        return v;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, q;
    cin >> n >> q;

    fenwick f(n+2), g(n+2);
    vector<int> a(n+2), b(n+2);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1 || t == 2) {
            int x, y;
            cin >> x >> y;

            int d = t == 1 ? 1 : -1;
            
            f.add(x, -!!a[x]);
            a[x] += d;
            f.add(x, !!a[x]);

            g.add(y, -!!b[y]);
            b[y] += d;
            g.add(y, !!b[y]);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x2++;
            y2++;
            cout << (f(x2)-f(x1) == x2-x1 || g(y2)-g(y1) == y2-y1 ? "Yes\n" : "No\n");
        }
    }
}