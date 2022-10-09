// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<ll> b(n);
    b[0] = a[0];
    for (int i : ra(0, n-1)) {
        b[i+1] = b[i] + a[i+1];
    }

    if (R::count_if(b, [](ll x) { return x < 0; }) || R::max(b) != b[n-1]) {
        cout << "-1\n";
        return 0;
    }

    compressor<ll> cx;
    for (ll& x : b) cx += x;

    cx();
    fenwick f(n+4);
    ll sol = 0;

    for (ll x : b) {
        sol += f(n+2-x);
        f.add(n+2-x, 1);
    }

    cout << sol << '\n';
}