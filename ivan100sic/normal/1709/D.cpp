// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int, class F = plus<T>>
struct sparse_table {
    vector<vector<T>> d;
    T e;
    F f;

    sparse_table(vector<T> a, T e = T(), F f = F()) : e(e), f(f) {
        d.push_back(a);
        int n = a.size();
        for (int h=1; h*2<=n; h<<=1) {
            int m = a.size() - h;
            vector<T> b(m);
            for (int i=0; i<m; i++)
                b[i] = f(a[i], a[i+h]);
            d.push_back(b);
            swap(a, b);
        }
    }

    T operator() (int l, int r) const {
        if (l >= r) return e;
        int i = 31 - __builtin_clz(r-l);
        return f(d[i][l], d[i][r-(1<<i)]);
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int& x : a) cin >> x;

    sparse_table st(a, -1, [](int x, int y) { return max(x, y); });

    int t;
    cin >> t;
    while (t--) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;

        if ((ys - yf) % k || (xs - xf) % k) {
            cout << "NO\n";
            continue;
        }

        if (ys > yf) swap(ys, yf);
        int x = xs + (n - xs) / k * k;

        if (ys != yf && st(ys-1, yf) >= x) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
        
}