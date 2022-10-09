// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[200005];
complex<ll> b[200005];

struct absoluter {
    vector<ll> a, s;
    ll n;

    // add (v-x)
    void add(ll v) {
        a.push_back(v);
    }

    void prepare() {
        R::sort(a);
        n = size(a);
        s.resize(n + 1);
        inclusive_scan(begin(a), end(a), begin(s) + 1);
    }

    // sum of abs(v-x) where x is given
    ll operator() (ll x) const {
        ll i = R::lower_bound(a, x) - begin(a);
        return s[n] - 2*s[i] - (n-i-i) * x;
    }

    ll brut(ll x) const {
        ll z = 0;
        for (ll v : a) z += abs(v-x);
        return z;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(1, n+1)) {
        int x;
        cin >> x;
        b[i] += x;
    }

    for (int i : ra(1, n+1)) {
        int x;
        cin >> x;
        b[i] -= x;
    }
    b[1] -= 1;
    b[1] += complex<ll>(0, -1);

    ll zero = 0;
    absoluter ma, pa;

    for (int i : ra(1, n+1)) {
        ll re = b[i].real(), im = b[i].imag();
        if (im == -1) {
            ma.add(re);
        } else if (im == 1) {
            pa.add(-re);
        } else {
            zero += abs(re);
        }

        for (int j=2*i; j<=n; j+=i) {
            b[j] -= b[i];
        }
    }

    ma.prepare();
    pa.prepare();

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << zero + ma(x) + pa(x) << '\n';
    }
}