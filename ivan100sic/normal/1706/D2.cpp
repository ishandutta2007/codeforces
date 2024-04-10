// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

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

using dli = divisor_loop<int>;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<dli::iterator> a;

        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            a.push_back(dli(x).begin());
        }

        vector<list<int>> q(100005);
        auto [lit, rit] = R::minmax_element(a, {}, [&](auto it) { return it.q; });
        int sol = rit->q - lit->q;

        int lo = lit->q;
        for (int i : ra(0, n)) {
            q[a[i].q].push_back(i);
        }

        for (int i=100000; i>=1; i--) {
            while (q[i].size() > 0) {
                sol = min(sol, i - lo);
                int x = q[i].front();
                q[i].pop_front();
                
                ++a[x];
                if (a[x].q != 0 && a[x].l <= k) {
                    q[a[x].q].push_back(x);
                    lo = min(lo, a[x].q);
                } else {
                    i = 0;
                    break;
                }
            }
        }

        cout << sol << '\n';
    }
}