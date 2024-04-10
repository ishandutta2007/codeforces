// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T>
struct divisor_loop {
    T n;

    divisor_loop(T n) : n(n) {}

    struct iterator {
        T n, q, l, r;

        tuple<T, T, T> operator*() {
            return {q, l, r};
        }

        iterator& operator++() {
            if (q == 1) {
                l = r = q = 0;
            } else {
                l = r + 1;
                q = n / l;
                r = n / q;
            }
            return *this;
        }

        bool operator== (const iterator& b) const {
            return tie(n, q, l, r) == tie(b.n, b.q, b.l, b.r);
        }

        bool operator!= (const iterator& b) const {
            return !(*this == b);
        }
    };

    iterator begin() {
        return {n, n, T(1), T(1)};
    }

    iterator end() {
        return {n, T(0), T(0), T(0)};
    }
};

int n, m;
int a[4000005];

int ad(int x, int y) {
    x += y;
    if (x >= m) x -= m;
    return x;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    a[1] = 1;
    int s = 1;
    for (int x=2; x<=n; x++) {
        a[x] = s;
        for (auto [q, l, r] : divisor_loop(x)) {
            if (q == x) continue;
            a[x] = ad(a[x], a[q] * 1ll * (r - l + 1) % m);
        }
        s = ad(s, a[x]);
    }

    cout << a[n] << '\n';
}