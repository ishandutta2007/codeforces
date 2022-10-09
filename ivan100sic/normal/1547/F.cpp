// Retired?
#include <bits/stdc++.h>
using namespace std;

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

struct gcdint {
    int x = 0;

    gcdint operator+ (const gcdint& b) const {
        return {gcd(x, b.x)};
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<gcdint> a(2*n);
        for (int i=0; i<n; i++) {
            cin >> a[i].x;
            a[i+n] = a[i];
        }

        sparse_table st(a);
        int l = 1, r = n-1, o = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int exp = st(0, m).x, ok = 1;
            for (int i=1; i<n; i++) {
                if (st(i, i+m).x != exp) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                o = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << o-1 << '\n';
    }   
}