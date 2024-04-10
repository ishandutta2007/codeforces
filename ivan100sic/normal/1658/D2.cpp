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

struct interval {
    int l, s;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;

    fenwick<int> f(1 << 19);

    while (t--) {
        int l, r;
        cin >> l >> r;
        int m = r-l+1;
        vector<int> a(m);
        for (int& x : a) cin >> x;

        for (int x : a) {
            f.add(x, 1);
        }

        // Break [l, r] into principal segments
        vector<interval> b;
        for (int t=l; t<=r;) {
            int s=1;
            while (t % s == 0 && t+s-1 <= r) {
                s *= 2;
            }
            s /= 2;
            b.push_back({t, s});
            t += s;
        }

        // Cover
        int sol = -1;
        for (int ai : a) {
            int x = ai ^ l, z = 0;
            for (auto [l, s] : b) {
                int l2 = l ^ (x & ~(s-1));
                z += f(l2+s) - f(l2);
            }
            if (z == m) {
                sol = x;
            }
        }

        cout << sol << '\n';

        for (int x : a) {
            f.add(x, -1);
        }       
    }
    
}