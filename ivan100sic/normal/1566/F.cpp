// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int>
struct minval {
    T x;
    minval(T x = numeric_limits<T>::max() / 2) : x(x) {}
    T operator() () const { return x; }
    minval operator+ (const minval& b) const { return min(x, b.x); }
    minval& operator+= (const minval& b) { return *this = *this + b; }
};

using minll = minval<ll>;

struct seg {
    int l, r;

    bool operator< (const seg& o) const {
        if (r != o.r) return r < o.r;
        return l > o.l;
    }
};

void remove_big(vector<seg>& v) {
    if (v.empty()) return;
    sort(begin(v), end(v));
    int i = 0;
    for (int j=1, n=v.size(); j<n; j++) {
        auto [l, r] = v[i];
        auto [x, y] = v[j];
        if (x > l) {
            // take
            v[++i] = v[j];
        }
    }
    v.resize(i + 1);
}

struct offer {
    ll a, l;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        sort(begin(a), end(a));

        vector<vector<seg>> b(n+1);

        for (int i=0; i<m; i++) {
            int l, r;
            cin >> l >> r;
            auto lit = lower_bound(begin(a), end(a), l);
            auto rit = lower_bound(begin(a), end(a), r);

            if (lit == rit && (lit == a.end() || *lit != l)) {
                b[lit - a.begin()].push_back({l, r});
            }
        }

        for (auto& v : b) {
            remove_big(v);
        }

        ll lspan = b[0].size() ? a[0] - b[0][0].r : 0;
        vector<ll> old;

        for (int i=0; i<=(int)b[1].size(); i++) {
            ll rspan = i ? b[1][i-1].l - a[0] : 0;
            ll w = lspan + rspan + min(lspan, rspan);
            old.push_back(w);
        }

        for (int j=2; j<=n; j++) {
            vector<offer> of(old.size());
            for (size_t i=0; i<old.size(); i++) {
                of[i] = {old[i], i + 1 == old.size() ? 0 : a[j-1] - b[j-1][i].r};
            }

            vector<minll> pref_min(of.size() + 1), suff_min(of.size() + 1);
            for (size_t i=0; i<of.size(); i++) {
                pref_min[i+1] = pref_min[i] + (of[i].a + of[i].l);
                auto [aq, lq] = of[of.size() - 1 - i];
                suff_min[i+1] = suff_min[i] + (aq + 2 * lq);
            }

            vector<ll> nu(b[j].size() + 1);
            
            for (size_t i=0; i<=b[j].size(); i++) {
                ll rspan = i ? b[j][i-1].l - a[j-1] : 0;
                int lcount = lower_bound(of.rbegin(), of.rend(), rspan,
                    [](offer o, ll x) { return o.l < x; }) - of.rbegin();
                
                ll w = min(
                    pref_min[old.size() - lcount]() + 2 * rspan,
                    suff_min[lcount]() + rspan);

                nu[i] = w;
            }

            swap(old, nu);
        }

        cout << old.back() << '\n';
    }
}